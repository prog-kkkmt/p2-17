#include "functions.h"
#include "Person.h"

extern vector <Money> dollar;

int main()
{
    system("chcp 1251");
    system("cls");
    double commission = get_commission();
    int val;
    Person jd;
    getff();
    print();

    if (dollar.size() < 1) //проверка на отсутствие данных в бд
    {
        cout << "Ассортимент пуст, обратитесь к менеджеру" << endl;
        cin >> val;
        if (val == 0)
            worker();
    }

    else
    {
        val = choose_your_destiny();
        if (val == 0)
        {
            worker();
        }
        else
        {
            double amount;
            cout << "Введите количество необходимой валюты: ";
            cin >> amount;
            jd.p_getpas();

            print_bill(jd, calculate_sum(amount, dollar[val-1].m_value, commission),
                        commission, amount, val);
        }
    }
    system("pause");
    return 0;
}
