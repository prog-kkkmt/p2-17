#pragma once
#include <iostream>

using namespace std;

class Money // класс дл€ валюты
{
public:
    string m_name;
    double m_value;

    Money(string name, double value)
    {
        this->m_name = name;
        this->m_value = value;
    }

    void m_print_name() // вывод названи€ с учЄтом '_'
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