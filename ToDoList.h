#pragma once
#include <vector>
#include "ToDo.h"
#include <string>
class ToDoList
{
	vector<ToDo> list;
public:

	ToDo& GetCase(int i) {
		return list[i];
	}
	int Len() {
		return list.size();
	}
	void Add(ToDo item) {
		list.push_back(item);
	}

	void Sort() {
		ToDo temp;
		for (int i = 0; i < list.size(); i++) {
			for (int j = 0; j < list.size() - 1; j++) {
				if (list[j].GetPrior() > list[j + 1].GetPrior()) {
					temp = list[j];
					list[j] = list[j + 1];
					list[j + 1] = temp;
				}
			}
		}
	}
	
	void deleteCase(int i) {
		list.erase(list.begin() + i);
	}

	bool isEmpty() {
		return (list.size() == 0) ? true : false;
	}
};

