#include "diagnosis.h"

Diagnos::Diagnos()
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
