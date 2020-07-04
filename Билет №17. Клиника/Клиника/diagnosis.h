#ifndef DIAGNOSIS_H
#define DIAGNOSIS_H

#include <iostream>
#include <fstream>
#include <string>
#include <locale>

using namespace std;

struct diagnos_str
{
    string code_diagnos;
	string name;
	string treatment;
};
class Diagnos
{
public:

    int kol = 0;
	diagnos_str *_diagnos;

	Diagnos()
	{
		string temp;
		fstream file("diagnoses.txt");
		if(!file.is_open())
        {
			cout << "Error";
		}
		while(!file.eof())
		{
			kol++;
			cout << kol;
			getline(file, temp);
		}
		file.clear();
		file.seekg(0);
		_diagnos = new diagnos_str[kol];
		for(int i = 0; i < kol; i++)
            file >> _diagnos[i].code_diagnos >> _diagnos[i].name >> _diagnos[i].treatment;

	}
};
#endif // DIAGNOSIS_H

