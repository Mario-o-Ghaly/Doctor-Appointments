#include "Appointment.h"
#include "Doctor.h"
#include "Patient.h"
#include "Person.h"
#include "temp.h"
#include <cstdlib>

int main() {
	string name, id, appoint;  //for storing patients/doctors names, id, and timing of appointments
	int age, available;        //for storing patients/doctors age, and the number of appointments a doctor can have
	cout<<"There are 3 doctors.\nEnter the number of patients: ";
	int P_num;                 //Patients number
	cin>>P_num;
	int D_num = 3;             //Doctors number
	// int P_num = 4;             
	Patient* Pt = new Patient[P_num];           //Patients array
	Queue <Doctor> doctors;
	Queue <Patient> patients;
	doctors.push(Doctor("Ayman", "100", 19, 7));  //the constructor of Doctor is (name, ID, age, available number of appointments)
	doctors.push(Doctor("Khaled", "200", 21, 9));
	doctors.push(Doctor("Mai", "300", 12, 1));

	//A loop to get the doctors data
	/*for (int i = 0; i < D_num; i++) {
		cout << "For Doctor " << i + 1 << " >>" << endl;
		cout << "\tEnter name: ";
		cin >> name;
		cout << "\tEnter ID: ";
		cin >> id;
		cout << "\tEnter age: ";
		cin >> age;
		cout << "\tEnter the number of appointments can be reserved: ";
		cin >> available;
		doctors.push(Doctor(name, id, age, available));
	}*/
	
	for (int i = 0; i < P_num; i++) {
		cout << "\nFor Patient " << i + 1 << " >>" << endl;
		cout << "\tEnter name: ";
		cin >> name;
		cout << "\tEnter ID: ";
		cin >> id;
		cout << "\tEnter age: ";
		cin >> age;
		cout << "\tEnter the timing of your desired appointment in the notation of 00:00 as a 24-hour format: ";
		cin >> appoint;
		float hour = 0, min = 0, j = 0;
		while (appoint[j] != ':')       //to get the hour from the string of the appointment
			hour = hour * 10 + (float)appoint[j++] - 48;
		while (++j < appoint.length())  //to get the minutes
			min = min * 10 + (float)appoint[j] - 48;
		
		*(Pt + i) = Patient(name, id, age, hour, min);   //assigning the array of patients
	}

	cout << endl;

	for (int i = 0; i < P_num; i++) {
		for (int j = 0; j < D_num; j++) {
			if (doctors.get_container().isAvailable((Pt + i)->getAppointment())) {  //check if the doctor available at the patient appointment
				cout << (Pt + i)->getName() << " should be assigned to Dr " << doctors.get_container().getName() << " at "; 
				(Pt + i)->printAppointment(); cout << endl;         //the output

				doctors.set_container((Pt + i)->getAppointment());  //This doctor will be assigned the desired appointment of patient i
				(Pt + i)->setDoctorID((doctors.get_container()).getID()); //Patient i will be asigned this Doctor's id
				(Pt + i)->setDoctorName(doctors.get_container().getName()); //Patient i will be assigned to this Doctor's name
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

	//To demonstrate what happened in the last loop, I created a queue of doctors
	//Then, I always compare if the first doctor in the queue is free at the patient's appointment
	//If the doctor is free, I assign them
	//Then I pop and push the doctor, so the next patient will be compared with the second doctor (who will be now in the begining of the queue)
	//If the doctor isn't free, I also pop and push, so the same patient will be compared with the second doctor (who will be now in the begining of the queue)
	//The patient's appointment will be checked by a number of times equal to the number of the doctros 
	
	cout << endl;
	for (int i = 0; i < P_num; i++) {  //sorting the patients array then oushing in the queue of patients
		int min = i;
		for (int j = i+1; j < P_num; j++)
			if ((Pt + j)->getAppointment() < (Pt+min)->getAppointment())
				min = j;
		Patient tempo = *(Pt + i);
		*(Pt + i) = *(Pt + min);
		*(Pt + min) = tempo;
		patients.push(*(Pt + i));
	}

	for (int i = 0; i < P_num; i++) { //final output
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
