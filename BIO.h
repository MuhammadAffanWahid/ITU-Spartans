#pragma once
#include<string>
#include"date.h"
using namespace std;
class BIO
{
public:
	string name;
	int age;
	date birth_date;
	char gender;
	string profession;
	string contact;
	BIO() {}
	BIO(string Name, int Age, date Birth_date, char Gender, string Contact, string Profession)
	{
		name = Name;
		age = Age;
		birth_date = Birth_date;
		gender = Gender;
		birth_date.SetDate(Birth_date.day, Birth_date.month, Birth_date.year);
		profession = Profession;
		contact = Contact;
	}
	BIO(string Name, int Age, date Birth_date, char Gender, string Contact)
	{
		name = Name;
		age = Age;
		birth_date = Birth_date;
		gender = Gender;
		birth_date.SetDate(Birth_date.day, Birth_date.month, Birth_date.year);
		contact = Contact;
		profession ="NOT_SPECIFIED";
	}
	void SetBio(string Name, int Age, date Birth_date, char Gender, string Contact, string Profession)
	{
		name = Name;
		age = Age;
		birth_date = Birth_date;
		gender = Gender;
		birth_date.SetDate(Birth_date.day, Birth_date.month, Birth_date.year);
		profession = Profession;
		contact = Contact;
	}
	void SetBio(string Name, int Age, date Birth_date, char Gender, string Contact)
	{
		name = Name;
		age = Age;
		birth_date = Birth_date;
		gender = Gender;
		birth_date.SetDate(Birth_date.day, Birth_date.month, Birth_date.year);
		profession = "NOT_SPECIFIED";
		contact = Contact;
	}

};

