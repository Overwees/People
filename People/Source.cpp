#include <iostream>
#include <Windows.h>
#include <vector>
#include <string>
#include <stdlib.h>
#include "person.h"
using namespace std;
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	bool find = true;
	unsigned a;
	vector <Person*> people;
	Person* human;
	human = new Person("Адам", Format::Мужской);
	people.push_back(human);
	human = new Person("Ева", Format::Женский);
	people.push_back(human);
	while (true)
	{
		int op;
		cout << "1. Просмотреть информацию о всех живых людях\n";
		cout << "2. Родить Человека\n";
		cout << "3. Изменить статус человека на 'мертв'\n";
		cout << "\n0.Выйти из программы\n";
		cout << "Выберите опцию:";
		cin >> op;
		system("Cls");
		if (op == 0)
		{
			break;
		}
		switch (op)
		{
		case 1:
			for (int i = 0; i < people.size(); i++)
			{
				cout << (*people[i]) << endl;
			}
			break;
		case 2:
			cout << "Введите ID матери:";
			try
			{
				int aMum, aDad, c;
				string name;
				bool exsist = false;
				cin >> aMum;
				for (int i = 0; i < people.size(); i++)
					if (people[i]->GetID() == aMum)
					{
						Person* child;
						exsist = true;
						int aDad, c;
						string name;
						cin.ignore();
						cout << "Введите Имя:";
						getline(cin, name);

						Format inputGender;
						cout << MENU_STRING_GENDER;
						while (true)
						{
							cin >> c;
							if (!((c < 1) || (c > GENDER_COUNT)))
								break;
							cout << "Ошибка ввода!Повторите снова!\n";
						}
						inputGender = (Format)c;

						cout << "Введите ID отца:";
						cin >> aDad;
						child = (*people[i]).GiveBirth(name.c_str(), inputGender, aDad);
						people.push_back(child);
						break;
					}
				if (exsist == false)
					throw exception("Данного человека не существует");
			}
			catch (exception s)
			{
				system("Cls");
				cout << s.what() << endl;
			}
			break;
		case 3:
			cout << "Введите ID человека:";
			cin >> a;
			for (int i = 0; i < people.size(); i++)
			{
				if (a == people[i]->GetID())
				{
					for (int j = i; j < people.size() - 1; j++)
					{
						human = people[j];
						people[j] = people[j + 1];;
						people[j + 1] = human;

					}
					break;
				}
			}
			people.pop_back();
			delete human;
			break;
		default:
			cout << "Ошибка ввода\n";
			break;
		}
		system("Pause");
		system("Cls");
	}
	return 0;
}