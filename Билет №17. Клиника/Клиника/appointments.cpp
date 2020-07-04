#include "appointments.h"

Appointment::Appointment()
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
