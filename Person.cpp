#include "Person.h"



Person::Person()
{
	this->name = NULL;
	this->nationality = NULL;
	setName("N/A");
	setAge(0);
	setNationality("N/A");
}

Person::Person(const char * name, const int age, const char * nationality)
{
	this->name = NULL;
	this->nationality = NULL;
	setName(name);
	setAge(age);
	setNationality(nationality);
}

Person::Person(const Person & p)
{
	this->name = NULL;
	this->nationality = NULL;
	*this = p;
}

Person::~Person()
{
	delete[] this->name;
	delete[] this->nationality;
}

const int Person::getAge() const
{
	return age;
}

const char * Person::getName() const
{
	return name;
}

const char * Person::getNationality() const
{
	return nationality;
}

void Person::setAge(int age)
{
	this->age = age;
}

void Person::setName(const char * name)
{
	delete[] this->name;
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
}

void Person::setNationality(const char * nationality)
{
	delete[] this->nationality;
	this->nationality = new char[strlen(nationality) + 1];
	strcpy(this->nationality, nationality);
}

void Person::print() const
{
	std::cout << *this;
}

const Person & Person::operator=(const Person & p)
{
	if (*this == p) return p;
	this->setAge(p.getAge());
	this->setName(p.getName());
	this->setNationality(p.getNationality());
	return *this;
}

bool Person::operator==(const Person & p) const
{
	if (this->getAge() != p.getAge()) return false;
	if (strcmp(this->getName(), p.getName()) != 0) return false;
	if (strcmp(this->getNationality(), p.getNationality()) != 0) return false;
	return true;
}

bool Person::operator<(const Person & p) const
{
	if (strcmp(this->getName(), p.getName()) < 0) return true;
	if (strcmp(this->getName(), p.getName()) == 0) {
		if (strcmp(this->getNationality(), p.getNationality()) < 0) return true;
		if (strcmp(this->getNationality(), p.getNationality()) == 0) {
			if (this->getAge() < p.getAge()) return true;
		}
	}
	return false;
}

bool Person::operator>(const Person & p) const
{
	return !(*this < p || *this == p);
}

bool Person::operator<=(const Person & p) const
{
	return *this == p || *this < p;
}

bool Person::operator>=(const Person & p) const
{
	return !(*this < p);
}

bool Person::operator!=(const Person & p) const
{
	return !(*this == p);
}

/*
Person::operator bool() const
{
	return !(this->age == 0 && this->name[0] == '\0' && this->nationality[0] == '\0');
}

bool Person::operator!() const
{
	return !(bool)*this;
}
*/

std::istream & operator>>(std::istream & i, Person & p)
{
	char tempName[100] = { '\0' };
	char tempNat[100] = { '\0' };
	i >> p.age >> tempName >> tempNat;
	p.setName(tempName);
	p.setNationality(tempNat);
	return i;
}

std::ostream & operator<<(std::ostream & o, const Person & p)
{
	return o << "Name: " << p.name << "\nAge: " << p.age << "\nNationality: " << p.nationality << "\n\n";
}
