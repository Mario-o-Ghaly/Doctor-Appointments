#include "Doctor.h"

Doctor::Doctor() {
	counter = 24;
	appointments = new Appointment[24];    //for (int i = 0; i < 24; i++)  (appointments + i)->setAppointment(-1, -1);
}
Doctor::Doctor(string _name, string _id, int _age, int num) : Person(_name, _id, _age) {
	counter = num;
	appointments = new Appointment[counter];   //for (int i = 0; i < counter; i++) (appointments + i)->setAppointment(-1, -1);
}
bool Doctor::isAvailable(const Appointment& rhs) {  //test for 2 conditions: 
	if (counter == 0)                               //First: if counter==0 then there are no other slots left to be resrved, 
		return false;
	for (int i = 0; i < counter; i++) {	           	
		if (*(appointments + i) == rhs) 		    //Second: if the Dr is not free at this specific time slot
			return false;
	}
	return true;
}

void Doctor::setID(string _id) { id = _id; }
void Doctor::setDrAppointment(const Appointment& rhs) {
	*(appointments + index) = rhs;
	index++;
	counter--;
}

string Doctor::getID() const { return id; }

Doctor::~Doctor(){
	if(appointments==NULL)
		delete[]appointments;
}
