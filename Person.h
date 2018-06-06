#ifndef PERSON_H
#define PERSON_H

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

class Person
{

	int age;
	char * name;
	char * nationality;

public:

	Person();
	Person(const char * name, const int age, const char * nationality);
	Person(const Person & p);
	~Person();

	const int getAge() const;
	const char * getName() const;
	const char * getNationality() const;

	void setAge(int age);
	void setName(const char * name);
	void setNationality(const char * nationality);

	void print() const;

	const Person & operator=(const Person & p);
	bool operator==(const Person & p) const;
	bool operator<(const Person & p) const;
	bool operator>(const Person & p) const;
	bool operator<=(const Person & p) const;
	bool operator>=(const Person & p) const;
	bool operator!=(const Person & p) const;
	//operator bool() const;
	//bool operator!() const;

	friend std::istream & operator>>(std::istream & i, Person & p);
	friend std::ostream & operator<<(std::ostream & o, const Person & p);

};

#endif PERSON_H