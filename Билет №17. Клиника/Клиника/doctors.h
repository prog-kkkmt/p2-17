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

	Doctors()
	{
		string temp;
		fstream file("doctorsin.txt");
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
		_doctors = new doctor_str[kol];
		for(int i=0; i < kol; i++)
            file >> _doctors[i].code_doctor >> _doctors[i].surname >> _doctors[i].name >> _doctors[i].patronymic >> _doctors[i].specialist;
	}
    void print_specialist()
    {
    	string mas[kol];
    	bool flag = false;
    	int z = 1;
    	mas[z - 1]= _doctors[0].specialist;
    	for(int i = 0; i < kol; i++)
        {
            flag = true;
			for (int j = 0; z > j; j++)
                if(mas[j] == _doctors[i].specialist)
                    flag = false;
            if(flag)
            {
				z++;
				mas[z - 1] = _doctors[i].specialist;
            }
    	}
		int m[z] = {0};
		for(int i = 0; i < kol; i++)
			for(int j = 0; j < a.kol; j++)
				if(a._appointment[j].code_doctor == _doctors[i].code_doctor)
					for(int b = 0; b < z; b++)
						if(mas[b] == _doctors[i].specialist)
                        {
                            m[b]++;
                            break;
                        }
		for(int i = 0; i < z; i++)
			cout << mas[i] << " - " << m[i] << endl;
    }
};

#endif // DOCTORS_H

