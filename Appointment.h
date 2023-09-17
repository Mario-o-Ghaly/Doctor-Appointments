#pragma once
#include <iostream>
#include <string>
#include <string.h>
#include "Person.h"
using namespace std;

struct Appointment {
private:              // Or protected?
	float hours, mins;
public:
	Appointment(float hour = -1, float min = -1);

	void setAppointment(float hour, float min);

	Appointment getAppointment() const;
	float getHours() const;
	float getMins() const;

	bool operator ==(const Appointment& rhs);
	bool operator <(const Appointment& rhs);
	bool operator >(const Appointment& rhs);
};