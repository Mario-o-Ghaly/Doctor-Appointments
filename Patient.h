#pragma once
#include <iostream>
#include <string>
#include <string.h>
#include "Appointment.h"
#include "Person.h"
using namespace std;

class Patient : public Person {
private:
	string doctorID, doctorName;
	Appointment appointment;
public:
	Patient();
	Patient(string _name, string _id, int _age, float hour, float min);

	void setID(string _id);
	void setDoctorID(string _id);
	void setDoctorName(string _name);
	void setAppointment(float hour, float min);
	void printAppointment();

	string getID() const;
	string getDoctorID() const;
	string getDoctorName()const;
	Appointment getAppointment() const;

	bool operator ==(const Patient& rhs);
	bool operator <(const Patient& rhs);
	bool operator >(const Patient& rhs);
};