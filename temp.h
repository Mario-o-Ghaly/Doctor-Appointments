#include <iostream>
#include <string>
#include "Appointment.h"
#include "Doctor.h"
using namespace std;
const int CAPACITY = 1000;

template <class T>
class Queue
{
	int back = -1;
	T container[CAPACITY];
public:

	bool push(T element) {
		if (back == (CAPACITY - 1))
			return false;
		else
		{
			back++;
			container[back] = element;
			return true;
		}
	}

	T pop() {
		/*if (back < 0)
			return "";
		else*/
		{
			T element = container[0];
			for (int i = 1; i <= back; i++)
				container[i - 1] = container[i];
			back--;
			return element;
		}
	}

	bool empty() { return (back < 0); }
	void print() {
		for (int i = 0; i <= back; i++)
			cout << container[i] << " ";
		cout << endl;
	}

	T get_container() const {
		return container[0];
	}

	void set_container( const Appointment & rhs) {
		container[0].setDrAppointment(rhs);
	}
};