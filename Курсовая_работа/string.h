#pragma once
#include <iostream>
#include <cstring>

using namespace std;

class String
{
protected:
    char* Str; // массив для строки
    int Length; // длина строки
public:
    String(); // конструктор c обьявлением строки
    String& operator = (String& t); // перегрузка операции =
    String& operator += (const String& t); // перегрузка операции +=
    bool operator == (const String& t) const; // перегрузка операции ==
    bool operator != (const String& t) const; // перегрузка операции !=
    bool is_empty() const; // проверка на пустоту строки
    const char* getStr() const; // вывод строки
    int getLength() const; // получение длины строки

    ostream& show(ostream& os); // вывод строки
    friend ostream& operator << (ostream& os, String& s) // перегрузка операции <<
    {
        return s.show(os);
    }
    friend istream& operator >> (istream& is, String& s) // перегрузка операции >>
    {
        char buf[10001];
        is.getline(buf, 10001);
        if (s.Length != 0) {
            delete[] s.Str;
        }
        s.Length = strlen(buf);
        s.Str = new char[s.Length + 1];
        strncpy(s.Str, buf, s.Length);
        s.Str[s.Length] = '\0';
        return is;
    }

    ~String();
};
