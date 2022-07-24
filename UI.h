#pragma once
#include "Fworker.h"
#include <conio.h>
#include <Windows.h>
#include "View.h"
#include "Control.h"
class UI
{
private:
	ToDoList list;
	FworkerCreator* Fwc;
	Fworker* s;
	Control control;
public:
	UI() {
		Fwc = new TXTFworkerCreator;
		s = Fwc->Create("save.txt");
		list = s->Load();
	}
	void Menu() {
		char ch = ' ';
		do {
			system("cls");
			ViewList()(list);
			cout << "\n\n\nInput what you want to do: \na - Add new activity;\nm - Change the mark on the completion of the case;\nf - Find activity by teg;\nd - Delete case;\ne - Exit;\n";
			cin >> ch;
			cin.ignore();
			switch (ch)
			{
			case 'a':
				control.Create(list);
				s->Save(list);
				break;
			case 'm':
			{
				if (list.isEmpty()) {
					cout << "Nothing to mark";
					Sleep(1000);
				}
				else {
					control.ChangeDone(list);
					s->Save(list);
				}
				break;
			}
			case 'f':
			{
				ToDoList findList = control.Find(list);
				if (findList.isEmpty()) {
					cout << "Nothing to find...";
				}
				else {
					ViewList()(findList);
				}
				cout << "\nPress eny key to continue...";
				_getch();
				break;
			}
			case 'd':
			{
				if (list.isEmpty()) {
					cout << "Nothing to delete";
					Sleep(1000);
				}
				else {
					control.DeleteCase(list);
					s->Save(list);
				}
				break;
			}
			}

		} while (ch != 'e');
	}


};

