#pragma once
#include <iostream>
#include <string>
#include <string.h>
using namespace std;

class Person {
protected:
	string name, id;
	int age;
public:
	Person(string _name = "XXXX", string _id = "XXX", int _age = 0);
	virtual void setName(string _name);
	virtual void setID(string _id) = 0;
	virtual void setAge(int _age);

	virtual string getName() const;
	virtual string getID() const = 0;
	virtual int getAge() const;

	virtual void print();
};