#pragma once
#include <iostream>

using namespace std;

class Money // класс для валюты
{
public:
    string m_name; // название валюты
    double m_value; // курс валюты к рублю

    Money(string name, double value)
    {
        this->m_name = name;
        this->m_value = value;
    }

    void m_print_name() // вывод названия с учётом '_'
    {
        for (int i = 0; i < m_name.length(); i++)
        {
            if (m_name[i] == '_')
                cout << " ";
            else
                cout << m_name[i];
        }
    }

    void m_print_value() // вывод курса
    {
        cout << m_value;
    }
};