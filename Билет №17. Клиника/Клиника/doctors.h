#ifndef DOCTORS_H
#define DOCTORS_H

#include <iostream>
#include <fstream>
#include <string>
#include "appointments.h"

using namespace std;

struct doctor_str
{
	string code_doctor;
    string surname;
    string name;
    string patronymic;
    string specialist;
};

class Doctors
{
public:

    Appointment a;
	int kol = 0;
	doctor_str *_doctors;

	Doctors();
    void print_specialist();
};

#endif // DOCTORS_H

