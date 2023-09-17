#include "Appointment.h"

Appointment::Appointment(float hour, float min) {
	setAppointment(hour, min);
}
void Appointment::setAppointment(float hour, float min) {
	hours = hour;
	mins = min;
}

Appointment Appointment::getAppointment() const { return *this; }   //return *this;
float Appointment::getHours() const { return hours; }
float Appointment::getMins() const { return mins; }

bool Appointment::operator==(const Appointment& rhs) {
	if (hours == rhs.getHours() && mins == rhs.getMins())
		return true;
	return false;
}

bool Appointment::operator<(const Appointment& rhs) {
	if (hours < rhs.getHours())
		return true;
	else if (hours == rhs.getHours())
		if (mins < rhs.getMins())
			return true;
	return false;
}

bool Appointment::operator>(const Appointment& rhs) {
	if (hours > rhs.getHours())
		return true;
	else if (hours == rhs.getHours())
		if (mins > rhs.getMins())
			return true;
	return false;
}