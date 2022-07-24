#pragma once
#include "ToDoList.h"
class Control
{
private:
	int InputNumber(string ask,int  minNumber = 1, int maxNumber = 9999)
	{
		int number;
		do {
			cout << ask;
			cin >> number;
			cin.clear();
			cin.sync();
			cin.ignore();
		} while (number < minNumber || number > maxNumber);
		return number;
	}
public:
	void Create(ToDoList& list)
	{
		string name, deadLine, teg;
		cout << "Input what do you need to do: ";
		getline(cin, name);
		cout << "Input dead line: ";
		getline(cin, deadLine);
		cout << "Input teg: ";
		getline(cin, teg);
		int priority = InputNumber("Input priority: ");
		ToDo item(name, deadLine, teg, priority, 15);
		list.Add(item);
	}

	void ChangeDone(ToDoList& list)
	{
		int number = InputNumber("Input number of the case, which you want to change mark of completion: \n", 1, list.Len());
		int newDone = (list.GetCase(number - 1).GetDone() == 15) ? 2 : 15;
		list.GetCase(number - 1).SetDone(newDone);
	}

	ToDoList Find(ToDoList& list) {
		string f;
		cout << "Input teg which you want to find: \n";
		getline(cin, f);
		ToDoList findList;
		for (int i = 0; i < list.Len(); i++) {
			if ((list.GetCase(i).GetTeg().find(f) != list.GetCase(i).GetTeg().npos)) {
				findList.Add(list.GetCase(i));
			}
		}
		return findList;
	}

	void DeleteCase(ToDoList& list)
	{
		int number = InputNumber("Input number of the case, which you want to delete\n", 1, list.Len());
		list.deleteCase(number - 1);
	}
};

