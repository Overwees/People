#include "Person.h"
#include <memory>
#include <vector>
unsigned Person::next_ID = 0;
struct info
{
	int ID;
	string status;
	Format sex;
};
vector <info> birth_book;
string toString(Format f)
{
	return GENDER_NAMES[(int)f - 1];
}

Person::Person() : ID(++next_ID)
{
	name = new char;
}

void Person::Erase()
{
	name = new char;
	delete name;
}

void Person::Clone(const Person& p)
{
	name = new char[strlen(p.name) + 1];
	strcpy(name, p.name);
	this->gender = p.gender;
	this->Dad_ID = p.Dad_ID;
	this->Mum_ID = p.Mum_ID;
}

Person::Person(const char* aname, Format aGender, int aDad_ID, int aMum_ID) :ID(next_ID++)
{

	SetName(aname);
	SetGender(aGender);
	SetDadID(aDad_ID);
	SetMumID(aMum_ID);
	info tmp;
	tmp.status = "Живой";
	tmp.sex = aGender;
	tmp.ID = ID;
	birth_book.push_back(tmp);
}


Person::~Person()
{
	for (int i = 0; i < birth_book.size(); i++)
	{
		if (this->GetID() == birth_book[i].ID)
		{
			birth_book[i].status = "Мертв";
			break;
		}
	}
	Erase();
}

Person* Person::GiveBirth(const char* aname, Format agender, int aDad_ID)
{
	Person* child = new Person(aname, agender, aDad_ID, this->GetID());
	return child;
}


Person::Person(const Person& p) : ID(next_ID++)
{
	Clone(p);
}

void Person::SetName(const char* aname)
{

	if (aname == NULL)
		throw "Invalid parameter (NULL)";
	if (aname[0] == '\0')
		throw "Invalid name length";
	name = new char[strlen(aname) + 1];
	strcpy(name, aname);
}

void Person::SetGender(Format aGender)
{
	gender = aGender;
}

void Person::SetDadID(int aDad_ID)
{
	if (aDad_ID >= 0)
	{
		if (aDad_ID > birth_book.size())
			throw exception("Ошибка! Такого человека не существует/Его нет в живых");
		for (int i = 0; i < birth_book.size(); i++)
		{
			if (aDad_ID == birth_book[i].ID)
			{
				if (birth_book[i].status == "Мертв")
					throw exception("Ошибка! Отец не может быть мертвым");
				if (toString(birth_book[i].sex) == "Мужской")
				{
					Dad_ID = aDad_ID;
					break;
				}
				else
					throw exception("Ошибка! Отец не может быть женского пола!");
			}

		}
	}
	else
		Dad_ID = aDad_ID;
}

void Person::SetMumID(int aMum_ID)
{
	if (aMum_ID >= 0)
	{
		if (aMum_ID > birth_book.size())
			throw exception("Ошибка! Такого человека не существует!/Его нет в живых");
		for (int i = 0; i < birth_book.size(); i++)
		{
			if (aMum_ID == birth_book[i].ID)
			{
				if (birth_book[i].status == "Мертв")
					throw exception("Ошибка! Мать не может быть мертвой");
				if (toString(birth_book[i].sex) == "Женский")
				{
					Mum_ID = aMum_ID;
					break;
				}
				else
					throw exception("Ошибка! Мать не может быть мужского пола!");
			}

		}
	}
	else
		Mum_ID = aMum_ID;
}


char* Person::GetName() const
{
	return name;
}

int Person::GetMumID() const
{
	return Mum_ID;
}

Format Person::GetGender() const
{
	return gender;
}

int Person::GetDadID() const
{
	return Dad_ID;
}


Person& Person::operator=(const Person& p)
{
	if (this == &p)
		return *this;
	name = new char[strlen(p.name) + 1];
	strcpy(name, p.name);
	this->gender = p.gender;
	this->Mum_ID = p.Mum_ID;
	this->Dad_ID = p.Dad_ID;

	return *this;
}

ostream& operator<<(ostream& s, const Person& p)
{

	s << "ID - " << p.ID << ", Имя - " << p.name << ", Пол - " << toString(p.gender);
	if (p.Dad_ID >= 0)
		for (int i = 0; i < birth_book.size(); i++)
		{
			if (p.Dad_ID == birth_book[i].ID)
				if (birth_book[i].status == "Мертв")
				{
					s << ", Отец мертв";
					break;
				}
				else
				{
					s << ", ID Отца - " << p.Dad_ID;
					break;
				}
		}
	if (p.Mum_ID >= 0)
		for (int i = 0; i < birth_book.size(); i++)
		{
			if (p.Mum_ID == birth_book[i].ID)
				if (birth_book[i].status == "Мертв")
				{
					s << ", Мать мертва";
					break;
				}
				else
				{
					s << ", ID Матери - " << p.Mum_ID;
					break;
				}
		}
	return s;
}