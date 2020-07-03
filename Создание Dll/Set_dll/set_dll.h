#ifndef SET_DLL_H
#define SET_DLL_H

#include "Set_dll_global.h"

class SET_DLL_EXPORT Set_dll
{
private:
    char *set;
    int size;
public:
    Set_dll();
    Set_dll addition(Set_dll Set_A, Set_dll Set_B);//Объединение множеств
    Set_dll disjunction(Set_dll Set_A, Set_dll Set_B);//Пересечение множеств
    bool equality(Set_dll Set_A, Set_dll Set_B);//Проверка на равенство множеств
    Set_dll difference(Set_dll Set_A, Set_dll Set_B);//Разность множеств
    Set_dll symmetrical_difference(Set_dll Set_A, Set_dll Set_B);//Симметричная разность множеств
    bool subset(Set_dll Set_A, Set_dll Set_B);// Проверка является множество 'B' подмножеством 'A'
    Set_dll get_set(QString text);
    QString get_text(Set_dll data);
    void test();
};

#endif // SET_DLL_H
