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

	Appointment();

};

#endif // APPOINTMENT_H


