#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Money.h"

using namespace std;

extern const string filename = "in.txt";
extern const string pasFileName = "passfile.txt";
extern const string commissionFileName = "commission.txt";
extern vector <Money> dollar;

void clear_buf() // очистка буфера ввода
{
    cin.clear(); //очистка
    cin.ignore(32767, '\n'); //игнорирование до enter
}

void getff() //данные из файла в вектор
{
    string name;
    double value;
    ifstream fin(filename);

    if (!fin.is_open())
    {
        cout << "Файл с валютой не найден" << endl;
        exit(0);
    }

    while (fin >> name >> value)
        dollar.push_back(Money(name, value));
    fin.close();
}

void print() //вывод таблы с данными на экран
{
    for (int i = 0; i < dollar.size(); i++)
    {
        cout << i + 1 << ". ";
        dollar[i].m_print_name();
        cout << " ";
        dollar[i].m_print_value();
        cout << endl;
    }
}

void vector_to_file() //запись таблицы с данными в файл "filename"
{
    ofstream fin(filename);
    for (int i = 0; i < dollar.size(); i++)
        fin << dollar[i].m_name << " " << dollar[i].m_value << endl;
    fin.close();
}

double get_commission() //получение комиссии из файла "commissionFileName"
{
    double commission;
    ifstream fin(commissionFileName);
    if (!fin.is_open())
    {
        cout << "Файл с комиссией не найден" << endl;
        exit(0);
    }
    fin >> commission;
    fin.close();
    return commission;
}

int choice_your_destiny() //функция выбора номера валюты
{
    int num;
    while (1)
    {
        if (dollar.size() < 2)
            cout << "Введите номер валюты: ";
        else
            cout << "Введите номер валюты от 1 до " << dollar.size() << ": ";
        cin >> num;
        if (num <= dollar.size() && num >= 0)
            break;
    }
    return num;
}

void add_field() // добавление поля
{
    clear_buf();
    cout << "Введите название валюты (пробелы замените '_'): ";
    string name;
    double value;
    cin.sync();  // синхронизация потоков (почитать или попробовать с разбиением одной строки)
    getline(cin, name);
    cout << "Введите курс к рублю: ";
    cin >> value;
    dollar.push_back(Money(name, value));
    vector_to_file();
}

void edit_field() // изменение курса поля
{
    int num;
    double value;
    print();
    cout << "Выберите номер поля: ";
    cin >> num;
    cout << "Введите новое значение: ";
    cin >> value;
    dollar[num - 1].m_value = value;
    vector_to_file();
}

void delete_field() //удаление поля
{
    int num;
    print();
    cout << "Выберите номер поля: ";
    cin >> num;
    dollar.erase(dollar.begin() + num - 1);
    vector_to_file();
}

void change_field() // изменение поля
{
    int num;
    string name;
    double value;
    print();
    cout << "Выберите номер поля: ";
    cin >> num;
    cout << "Введите новое название: ";
    cin >> name;
    cout << "Введите новое значение: ";
    cin >> value;
    dollar[num - 1].m_name = name;
    dollar[num - 1].m_value = value;
    vector_to_file();
}

void change_password() //смена пароля
{
    int tries_not_null = 4;
    string password, filePassword;
    ifstream file(pasFileName);
    cout << "Введите старый пароль: ";
    file >> filePassword;
    while (tries_not_null) //цикл для проверки правильности пароля
    {
        cin >> password;
        if (filePassword == password)
        {
            file.close();
            ofstream file(pasFileName);
            cout << "Введите новый пароль: ";
            cin >> password;
            file << password;
            break;
        }
        else
        {
            tries_not_null--;
            if (tries_not_null != 0)
                cout << "Неправильный пароль, попробуйте ещё раз: ";
            else
                cout << "Иди, вспоминай пароль, дубина";
        }
    }
    file.close();
}

void change_commission() //изменение комиссии
{
    double commission;
    cout << "Предыдущее значение комисии: " << get_commission() << endl;;
    cout << "Введите новое значение комиссии (%): ";
    cin >> commission;
    ofstream fout(commissionFileName);
    fout << commission;
    fout.close();
}

void worker_menu() // меню для работника
{
    int num = 0;

    while (num != 7)
    {
        system("cls");
        cout << "1. Изменение курса валюты" << endl;
        cout << "2. Добавление поля" << endl;
        cout << "3. Изменение поля" << endl;
        cout << "4. Удаление поля" << endl;
        cout << "5. Изменение пароля" << endl;
        cout << "6. Изменение комиссии" << endl;
        cout << "7. Выход" << endl;
        cout << "Выберите действие: ";
        cin >> num;
        cout << endl;
        switch (num)
        {
        case 1:
            edit_field();
            break;
        case 2:
            add_field();
            break;
        case 3:
            change_field();
            break;
        case 4:
            delete_field();
            break;
        case 5:
            change_password();
            break;
        case 6:
            change_commission();
            break;
        }
    }
}

void worker() // проверка пароля и доступ к режиму редактирования данных
{
    int tries_not_null = 4;
    string password, filePassword;
    ifstream file("passfile.txt");
    if (!file.is_open())
    {
        cout << "Файл с паролем не найден" << endl;
        exit(0);
    }
    file >> filePassword;
    cout << "Введите пароль: ";
    while (tries_not_null)
    {
        cin >> password;
        if (filePassword == password)
        {
            worker_menu();
            break;
        }
        else
        {
            tries_not_null--;
            if (tries_not_null != 0)
                cout << "Неправильный пароль, попробуйте ещё раз: ";
            else
                cout << "Не пущу, пока не вспомнишь пароль" << endl;
        }
    }
    file.close();
}

long double calculate_sum(double coins, double value, double commission) //вычисление итогового счёта
{
    double total;
    total = coins * value + (coins * value / 100 * commission);
    return total;
}