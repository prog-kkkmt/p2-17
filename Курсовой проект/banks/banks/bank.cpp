#include "functions.h"
#include "Person.h"

extern vector <Money> dollar;

int main()
{
    system("chcp 1251");
    system("cls");
    cout << "Для доступа к режиму редактирования нажмите '0', пароль - '0'" << endl;
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
        val = choice_your_destiny();
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

            jd.p_print_bill(calculate_sum(amount, dollar[val-1].m_value, commission),
                        commission, amount, val);
        }
    }
    return 0;
}
