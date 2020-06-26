#include <iostream>
#include <cstdlib>
#include <math.h>
#include <fstream>
#include <locale>
#include <conio.h>
#include <string>
#include "summ.h"
#include "razn.h"
#include "multiplication.h"
#include "division.h"
#include "sqrt.h"
#include "settings.h"

using namespace std;

int main()
{
    setlocale(LC_ALL,"Russian");
    int input_number;
begin:
    cout<<"==========Меню============"<<endl;
    cout<<"||1. Сложение           ||"<<endl;
    cout<<"||2. Вычитание          ||"<<endl;
    cout<<"||3. Умножение          ||"<<endl;
    cout<<"||4. Деление            ||"<<endl;
    cout<<"||5. Корень числа       ||"<<endl;
    cout<<"||6. Настройки          ||"<<endl;
    cout<<"||0. Выход              ||"<<endl;
    cout<<"=========================="<<endl;
    cout<<endl;
    cout<<"Ваш выбор: ";
    cin>>input_number;

    switch(input_number)
    {
    case 1:
    {
        system("cls");
        class_summ Summ_func;
        Summ_func.summ();
        system("pause");
        system("cls");
        break;
    }
    case 2:
    {
        system("cls");
        class_razn Razn_func;
        Razn_func.razn();
        system("pause");
        system("cls");
        break;
    }
    case 3:
    {
        system("cls");
        class_multiplication Mult_func;
        Mult_func.multiplication();
        system("pause");
        system("cls");
        break;
    }
    case 4:
    {
        system("cls");
        class_division Div_func;
        Div_func.division();
        system("pause");
        system("cls");
        break;
    }
    case 5:
    {
        system("cls");
        class_sqrt Sqrt_func;
        Sqrt_func.Sqrt();
        system("pause");
        system("cls");
        break;
    }
    case 6:
    {
        system("cls");
        settings Sett_func;
        Sett_func.open_settings();
        system("cls");
        break;
    }
    case 0:
    {
        system("cls");
        cout<<"Выход из программы..."<<endl;
        return 0;
    }
    default:
    {
        system("cls");
        cout<<"Неправильный ввод, пожалуйста, повторите попытку..."<<endl<<endl;
        system("pause");
        system("cls");
        break;
    }
    }
    goto begin;
}
