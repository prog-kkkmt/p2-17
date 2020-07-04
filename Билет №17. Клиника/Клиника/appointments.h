#ifndef APPOINTMENT_H
#define APPOINTMENT_H

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct appointment_str
{
    string code_appointment;
    string code_doctor;
    string code_patient;
    string data;
    string time;
    string code_diagnos;
};

class Appointment
{
public:

    int kol = 0;
	appointment_str *_appointment;

	Appointment()
	{
		string temp;
		fstream file("appointments.txt");
		if(!file.is_open())
        {
			cout << "Error";
		}
		while(!file.eof())
		{
			kol++;
			getline(file, temp);
		}
		file.clear();
		file.seekg(0);
		_appointment = new appointment_str[kol];
		for(int i = 0; i < kol; i++)
			file >> _appointment[i].code_appointment >> _appointment[i].code_doctor >> _appointment[i].code_patient >> _appointment[i].data >> _appointment[i].time >> _appointment[i].code_diagnos;
	}
};

#endif // APPOINTMENT_H


