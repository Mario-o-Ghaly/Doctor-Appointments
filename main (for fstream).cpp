#ifndef A
#define A
#include "Appointment.h"
#include "Doctor.h"
#include "Patient.h"
#include "Person.h"
#include "temp.h"
#include <cstdlib>
#include <fstream>

int main() {
	ifstream infile("doctors.txt");
	if (!infile.is_open()) {
		cout << "Error openning the file ";
		exit(1);
	}

	string name, appoint, id, x;
	int age, available;
	Queue <Doctor> doctors;
	Queue <Patient> patients;
	string hour, min;

	Patient* Pt = new Patient[4];
	while (!infile.eof()) {
		getline(infile, name);
		getline(infile, id);
		getline(infile, x);
		age = stoi(x);
		doctors.push(Doctor(name, id, age));

		getline(infile, x);
		for (int i = 0; i < stoi(x) * 2; i++) {
			getline(infile, hour);
			getline(infile, min);
			doctors.set_container(Appointment(stof(hour), stof(min)));
		}
	}

	infile.close();

	ifstream infile2("patients.txt");
	if (!infile2.is_open()) {
		cout << "Error openning the file ";
		exit(1);
	}

	int i = 0;
	while (!infile2.eof()) {
		getline(infile, name);
		getline(infile, id);
		getline(infile, x);
		age = stoi(x);
		getline(infile, hour);
		getline(infile, min);
		*(Pt + i) = Patient(name, id, age, stof(hour), stof(min));
		i++;
	}

	cout << endl;

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 3; j++) {
			if (doctors.get_container().isAvailable((Pt + i)->getAppointment())) {  
				cout << (Pt + i)->getName() << " should be assigned to Dr " << doctors.get_container().getName() << " at ";
				(Pt + i)->printAppointment(); cout << endl;        

				doctors.set_container((Pt + i)->getAppointment());  
				(Pt + i)->setDoctorID((doctors.get_container()).getID()); 
				(Pt + i)->setDoctorName(doctors.get_container().getName()); 
				Doctor temporary = doctors.pop();
				doctors.push(temporary);
				break;
			}
			else {
				Doctor temporary = doctors.pop();
				doctors.push(temporary);
			}
		}
	}

	cout << endl;
	for (int i = 0; i < 4; i++) {  
		int min = i;
		for (int j = i + 1; j < 4; j++)
			if ((Pt + j)->getAppointment() < (Pt + min)->getAppointment())
				min = j;
		Patient tempo = *(Pt + i);
		*(Pt + i) = *(Pt + min);
		*(Pt + min) = tempo;
		patients.push(*(Pt + i));
	}

	for (int i = 0; i < 4; i++) { //final output
		Patient x = patients.pop();
		if (x.getDoctorID() == "0")
			cout << x.getName() << " doesn't have an appointment " << endl;
		else {
			cout << x.getName() << " has an appointment at: "; x.printAppointment(); cout << " with Dr " << x.getDoctorName()
				<< endl;
		}
	}
	return 0;
}
#endif A