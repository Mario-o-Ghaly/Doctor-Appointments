#pragma once
#include "Person.h"
#include "Appointment.h"
using namespace std;

class Doctor :public Person {
private:
	int counter, index = 0;        //For assigning the appointments reserved in the array   
	Appointment* appointments = NULL;     //pointer to a number of appointments a doctor can be reserved
public:
	Doctor();
	Doctor(string _name, string _id, int age, int num = 24);
	bool isAvailable(const Appointment& rhs);

	void setID(string _id);
	void setDrAppointment(const Appointment& rhs);

	string getID() const;
	~Doctor();
};