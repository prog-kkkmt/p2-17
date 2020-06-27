#include "string.h"
#include <iostream>
#include <cstring>

using namespace std;

// Конструктор класса String
String::String()
{
    Str = new char[1];
    Str[0] = '\0';
    Length = 0;
}

String& String::operator = (String& t)
{
    // Смена местами значения срок
    swap(Length, t.Length);
    swap(Str, t.Str);
    return *this;
}

String& String::operator += (const String& t)
{
    // Увеличение длины строки
    int newLength = Length + t.Length;
    // Создание новой строки размером длин двух строк
    char* newStr = new char[newLength + 1];
    strcpy(newStr, Str);
    strcat(newStr, t.Str);
    delete[] Str; // очищение исходной строки
    Str = newStr;
    Length = newLength;
    return *this;
}
// Сравнение строк на равенство
bool String::operator == (const String& t) const
{
    return Length == t.Length && strcmp(Str, t.Str) == 0;
}
// Сравнение строк на неравенство
bool String::operator != (const String& t) const
{
    return !(operator == (t));
}
// Проверка строки на пустоту
bool String::is_empty() const
{
    return Str == 0 || Str[0] == '\0';
}

const char* String::getStr() const
{
    return Str;
}

int String::getLength() const
{
    return Length;
}

ostream& String::show(ostream& os)
{
    return os << "\"" << (Str ? Str : "") << "\""; // Возвращает поток со строкой
}

// Деструктор - очищает строку и ставит длину строки 0
String::~String()
{
    Length = 0;
    delete[] Str;
    Str = 0;
}
