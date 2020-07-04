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

	Diagnos();
};
#endif // DIAGNOSIS_H

