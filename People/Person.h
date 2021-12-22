#pragma once
#pragma warning(disable: 4996)
#include <iostream>
#include <string>
using namespace std;
constexpr auto START_LINE_GENDER = __LINE__;
enum class Format
{
	Мужской = 1,
	Женский
};
constexpr auto GENDER_COUNT = __LINE__ - START_LINE_GENDER - 3;
const string GENDER_NAMES[] = { "Мужской","Женский" };
const string MENU_STRING_GENDER = "Выберите пол(1 - Мужской, 2 - Женский):";

class Person
{
private:
	char* name;
	Format gender;
	int Dad_ID;
	int Mum_ID;
	static unsigned next_ID;
	const unsigned ID;
	void Erase();
	void Clone(const Person&);
public:
	Person();
	void SetName(const char* aname);
	void SetDadID(int aDad_ID);
	void SetMumID(int aMum_ID);
	void SetGender(Format aGenger);
	Person(const char* aname, Format agender, int aDad_ID = -1, int aMum_ID = -1);
	int GetID() { return ID; }
	~Person();
	Person* GiveBirth(const char* aname, Format agender, int aDad_ID = -1);
	char* GetName() const;
	int GetDadID()const;
	int GetMumID()const;
	Format GetGender()const;
	Person(const Person&);
	Person& operator = (const Person&);
	friend ostream& operator<<(ostream&, const Person&);
};



