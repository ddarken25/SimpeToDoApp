#pragma once
#include "ToDo.h"
class ViewCase
{
public:

	void operator()(ToDo item)
	{
		cout << "\033[38;5;00" << item.GetDone() << "m";
		cout << "\n-------------------------------\n";
		cout << "Must to do until: " << item.GetDeadLine() << "\n";
		cout << item.GetName() << "\n";
		cout << "#" << item.GetTeg() << "\n";
		cout << "Priority: " << item.GetPrior() << "\n";
		cout << "-------------------------------\n\033[0m";
	}

};


class ViewList
{
public:

	void operator()(ToDoList& list)
	{
		if (list.isEmpty()) {
			cout << "ToDo List is empty. Add something....\n";
		}
		else {
			list.Sort();
			for (int i = 0; i < list.Len(); i++) {
				ViewCase()(list.GetCase(i));
			}
		}
	}

};