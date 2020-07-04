#include "patients.h"

Patient::Patient()
{
    string temp;
    fstream file("patients.txt");
    if(!file.is_open())
    {
        cout<<"hello";
    }
    while(!file.eof())
    {
        kol++;
        getline(file, temp);
    }
    file.clear();
    file.seekg(0);

    _patient = new patient_str[kol];

    for(int i = 0; i < kol; i++)
        file >> _patient[i].code_patient >> _patient[i].family >> _patient[i].name >> _patient[i].fathername >> _patient[i].adress;
}
void Patient::print_patient()
{
    for(int i = 0; i < kol; i++)
    {
        int k = 0;
        for(int j = 0; j < a.kol; j++)
            if(a._appointment[j].code_patient == _patient[i].code_patient)
                k++;
            if(k > 1)
                cout << _patient[i].code_patient << " " << _patient[i].family << " " << _patient[i].name << " " << _patient[i].fathername << " " << endl;
    }
}
