#pragma once
#include <iomanip>
#include <vector>
#include "Money.h"

using namespace std;

extern vector <Money> dollar;

class Person // класс для паспортных данных пользователя
{
public:
    string p_f;
    string p_i;
    string p_o;
    int p_num;

    void p_getpas()
    {
        cout << "Введите свои паспортные данные (ФИО, серия и №) через пробел: ";
        cin >> p_f >> p_i >> p_o >> p_num;
    }

    void p_print_fio()
    {
        cout << p_f << " " << p_i << " " << p_o;
    }

    void p_print_num()
    {
        cout << p_num;
    }

    void p_print_bill(long double total, double commission, double amount, int val) // печать квитанции
    {
        cout << "\nЧек";
        cout << "\nФИО клиента: ";
        p_print_fio();

        cout << "\nНомер паспорта: ";
        p_print_num();

        cout << "\nВалюта: ";
        dollar[val - 1].m_print_name();

        cout << "\nКоличество валюты: " << amount;

        cout << "\nКурс: ";
        dollar[val - 1].m_print_value();
        cout << "р за единицу (";
        dollar[val - 1].m_print_name();
        cout << ")";

        cout << "\nКомиссия: " << commission << "%";
        cout << fixed << setprecision(2) << "\nИтого к оплате: " << total << " р";

        cout << endl;
    }
};