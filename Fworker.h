#pragma once
#include "ToDoList.h"
#include <fstream>
#include <Windows.h>
class Fworker
{
protected:
	string path;
public:
	Fworker(string p) {
		path = p;
	}
	virtual void Save(ToDoList& list) = 0;
	virtual ToDoList Load() = 0;
};


class TXTFworker :public Fworker
{
public:
	TXTFworker(string p) : Fworker(p) {};
	void Save(ToDoList& list) override
	{
		ofstream file;
		file.open(path);
		if (file.is_open()) {
			for (int i = 0; i < list.Len(); i++) {
				if (!i) {
					file << list.GetCase(i).GetName() << "\n";
				}
				else {
					file << "\n" << list.GetCase(i).GetName() << "\n";
				}
				file << list.GetCase(i).GetDeadLine() << "\n";
				file << list.GetCase(i).GetTeg() << "\n";
				file << list.GetCase(i).GetPrior() << "\n";
				file << list.GetCase(i).GetDone();
			}
			file.close();
		}
	}

	ToDoList Load() override {
		ToDoList list;
		string name, deadLine, teg, p_str, d_str;
		int priority, done;
		ifstream file;
		file.open(path);
		if (file.peek() != EOF && file.is_open()) {
			while (!file.eof()) {
				getline(file, name);
				getline(file, deadLine);
				getline(file, teg);
				getline(file, p_str);
				getline(file, d_str);
				priority = stoi(p_str);
				done = stoi(d_str);
				ToDo item(name, deadLine, teg, priority, done);
				list.Add(item);
			}
			file.close();
		}
		return list;
	}
};



class FworkerCreator
{
public:
	virtual Fworker* Create(string path) = 0;
};


class TXTFworkerCreator: public FworkerCreator
{
	Fworker* Create(string path)
	{
		Fworker* s = new TXTFworker{ path };
		return s;
	}
};