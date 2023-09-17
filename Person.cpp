#include "Person.h"

Person::Person(string _name, string _id, int _age) { name = _name, id = _id, age = _age; }
void Person::setName(string _name) { name = _name; }
void Person::setAge(int _age) { age = _age; }

string Person::getName() const { return name; }
int Person::getAge() const { return age; }

void Person::print() {
	cout << "Name: " << name;
	cout << "\nID: " << id;
	cout << "\nAge: " << age;
}