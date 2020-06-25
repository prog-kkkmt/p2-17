#pragma once
#include <iomanip>
#include <vector>
#include "Money.h"

using namespace std;

class Person // класс для паспортных данных пользователя
{
public:
    string p_f; // фамилия
    string p_i; // имя
    string p_o; // отчество
    string p_num; // номер паспорта

    void p_getpas() // метод получения пасортных данных клиента
    {
        cout << "Введите свои паспортные данные (ФИО, серия и №) через пробел: ";
        cin >> p_f >> p_i >> p_o >> p_num;
    }

    void p_print_fio() //  вывод ФИО
    {
        cout << p_f << " " << p_i << " " << p_o;
    }

    void p_print_num() // вывод номера паспорта
    {
        cout << p_num;
    }
};