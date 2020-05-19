#include "Recruitment_agency.hpp"

int main()
{
    setlocale(LC_ALL, "Rus");
    Recruitment_agency r;
    int x = 0;

    do
    {
        cout << "Выбирите таблицу: " << endl << endl;
        cout << "1. Должности" << endl;
        cout << "2. Профессии" << endl;
        cout << "3. Образование" << endl;
        cout << "4. Уровень владения компьютером" << endl;
        cout << "5. Вакансии" << endl;
        cout << "6. Выход" << endl;
        cout << endl;
        cin >> x;

        switch(x)
        {
            case 1: r.post_menu(); break;
            case 2: r.professions_menu(); break;
            case 3: r.form_menu(); break;
            case 4: r.computer_LVL_menu(); break;
            case 5: r.vacancy_menu(); break;
            case 6: break;
            default:
                cout << "Неверно введен пункт меню" << endl;
                break;

        };
    }
    while(x != 6);

    return 0;
}
