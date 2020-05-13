#include <iostream>
#include <string>
#include <fstream>
#include <locale>
#include <cstdlib>

using namespace std;

struct TimeTable
{
    int Train_number;
    int Path_start;
    int Path_time;
    int Path_end;
};

int main()
{
    setlocale(LC_ALL, "Rus");

    ifstream in("in.txt");

    int countLine = 0;
    string line;

    while (getline(in, line))
    {
       countLine++;
    }
    in.close();

    in.open("in.txt");
    TimeTable *trains = new TimeTable[countLine];

    int i = 0;
    while (in)
    {
        in >> trains[i].Train_number >> trains[i].Path_start >> trains[i].Path_time >> trains[i].Path_end;
        i++;
    }
    in.close();

    for (;;)
    {
        cout << "  Вид действия:" << endl;
        cout << "  1 - Сортировка по времени прибытия(По возростанию)" << endl;
        cout << "  2 - Поезда находящиеся в пути менее 9 часов" << endl;
        cout << "  3 - Отобрать поезда, которые отправляются из Москвы от девяти до одиннадцати часов вечера." << endl;
        cout << "  4 - Отсортировать данные таблицы по возрастанию по номерам поездов" << endl;
        cout << "  5 - Отсортировать данные таблицы по времени прибытия поездов в Санкт-Петербург (по убыванию)." << endl;
        cout << "  7 - Отсортировать данные таблицы по времени нахождения поезда в пути (по возрастанию)." << endl;
        cout << "  8 - Отсортировать данные таблицы по времени нахождения поезда в пути (по убыванию)." << endl;
        cout << "  9 - завершение работы" << endl;
        cout << "  Выберите операцию: ";

        int x;
        cin >> x;

        switch (x)
        {
            case 1:
            {
                ofstream of("of.txt");
                for(int i = 0; i < countLine - 1; i++)
                {
                    int si = i;
                    for(int j = i + 1; j < countLine; j++)
                    {
                        if(trains[j].Path_end < trains[si].Path_end)
                        {
                            si = j;
                        }
                    }
                    swap(trains[i].Path_end, trains[si].Path_end);
                }
                for(int i = 0; i < countLine; i++)
                {
                    of << trains[i].Path_end << endl;
                }
            }

        }
        return 0;
    }
}
