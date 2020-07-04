#ifndef PATIENTS_H
#define PATIENTS_H

#include <iostream>
#include <fstream>
#include <string>
#include "appointments.h"

using namespace std;

struct patient_str
{
    string code_patient;
	string family;
	string name;
	string fathername;
	string adress;
};
class Patient
{
public:

    Appointment a;
	int kol = 0;
	patient_str * _patient;

	Patient();
    void print_patient();
};
#endif // PATIENTS_H

