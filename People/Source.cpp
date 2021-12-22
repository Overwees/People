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
	human = new Person("����", Format::�������);
	people.push_back(human);
	human = new Person("���", Format::�������);
	people.push_back(human);
	while (true)
	{
		int op;
		cout << "1. ����������� ���������� � ���� ����� �����\n";
		cout << "2. ������ ��������\n";
		cout << "3. �������� ������ �������� �� '�����'\n";
		cout << "\n0.����� �� ���������\n";
		cout << "�������� �����:";
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
			cout << "������� ID ������:";
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
						cout << "������� ���:";
						getline(cin, name);

						Format inputGender;
						cout << MENU_STRING_GENDER;
						while (true)
						{
							cin >> c;
							if (!((c < 1) || (c > GENDER_COUNT)))
								break;
							cout << "������ �����!��������� �����!\n";
						}
						inputGender = (Format)c;

						cout << "������� ID ����:";
						cin >> aDad;
						child = (*people[i]).GiveBirth(name.c_str(), inputGender, aDad);
						people.push_back(child);
						break;
					}
				if (exsist == false)
					throw exception("������� �������� �� ����������");
			}
			catch (exception s)
			{
				system("Cls");
				cout << s.what() << endl;
			}
			break;
		case 3:
			cout << "������� ID ��������:";
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
			cout << "������ �����\n";
			break;
		}
		system("Pause");
		system("Cls");
	}
	return 0;
}