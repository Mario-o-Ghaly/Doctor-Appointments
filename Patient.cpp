#include "Patient.h"
#include "Appointment.h"

Patient::Patient() { doctorID = "0"; }
Patient::Patient(string _name, string _id, int _age, float hour, float min) :Person(_name, _id, _age) {
	doctorID = "0";
	appointment = Appointment(hour, min);
}

void Patient::setID(string _id) { id = _id; }
void Patient::setDoctorID(string _id) { doctorID = _id; }
void Patient::setDoctorName(string _name) { doctorName = _name; }
void Patient::setAppointment(float hour, float min) { 
	appointment.setAppointment(hour, min);          //call the setAppointment function of the Appointment struct
} 

void Patient::printAppointment(){                  //For the final output
	if (appointment.getMins() == 0)
		cout << appointment.getHours() << ":" << appointment.getMins() << 0;  //call the functions of the Appointment struct
	else cout << appointment.getHours() << ":" << appointment.getMins();  
}

string Patient::getID() const { return id; }
string Patient::getDoctorID() const { return doctorID; }
string Patient::getDoctorName() const { return doctorName; }
Appointment Patient::getAppointment() const { return appointment; }

//Call the overloaded operators of the Appointment struct
bool Patient::operator ==(const Patient& rhs) {        
	return (appointment == rhs.appointment);           
}
bool Patient::operator <(const Patient& rhs) {
	return (appointment < rhs.appointment);
}
bool Patient::operator >(const Patient& rhs) {
	return (appointment > rhs.appointment);
}

