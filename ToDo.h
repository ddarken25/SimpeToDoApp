#pragma once
#include <iostream>
#include <iomanip>
using namespace std;
class ToDo
{
	string name;
	string deadLine;
	string teg;
	int priority;
	int done;
public:
	ToDo() {
		name = "";
		deadLine = "";
		teg = "";
		priority = 0;
		done = 15;
	}
	ToDo(string n, string dl, string t, int p, int d) {
		name = n;
		deadLine = dl;
		priority = p;
		done = d;
		teg = t;
	}
	void SetDone(int d) {
		done = d;
	}
	string GetName() {
		return name;
	}
	string GetDeadLine() {
		return deadLine;
	}
	string GetTeg() {
		return teg;
	}
	int GetPrior() {
		return priority;
	}
	int GetDone() {
		return done;
	}
};

