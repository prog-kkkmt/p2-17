#include "Recruitment_agency.hpp"
void Recruitment_agency::write_to_file_vacancy(vector<vacancy>& table5, string S5)
{
    ofstream of(S5);
    for(int i = 0; i < table5.size(); i++)
    {
        of << table5[i].vacancy_cod << " " << table5[i].publ_date << " " << table5[i].vacancy_name << " " << table5[i].salary << " " << table5[i].feasibility << " " << table5[i].post_cod << " " <<table5[i].form_cod << " " << table5[i].LVL_cod << endl;
    }
    of.close();
}
void Recruitment_agency::add_to_vacancy_vector(string S5)
{
    ifstream in(S5);
    while(in >> count5.vacancy_cod >> count5.publ_date >> count5.vacancy_name >> count5.salary >> count5.feasibility >> count5.post_cod >> count5.form_cod >> count5.LVL_cod)
    {
        table5.push_back(count5);
    }
    in.close();
}
void Recruitment_agency::vacancy_write()
{
    cout << "_________________________________________________________________________________" << endl;
    for(int i = 0; i < table5.size(); i++)
    {
        cout << "|" << table5[i].vacancy_cod << "| " << table5[i].publ_date << " " << table5[i].vacancy_name << " " << table5[i].salary << " " << table5[i].feasibility << " " << table5[i].post_cod << " " <<table5[i].form_cod << " " << table5[i].LVL_cod << endl;
    }
    cout << "_________________________________________________________________________________" << endl;
    cout << endl;
}
void Recruitment_agency::vacancy_delete()
{
    int num, i = 0;
    cout << "Введите номер удаляемой вакансии: ";
    cin >> num;
    while(num != table5[i].vacancy_cod)
    {
        i++;
    }
    table5.erase(table5.begin() + i);
    write_to_file_vacancy(table5, S5);
}
void Recruitment_agency::vacancy_add()
{
    cin >> count5.vacancy_cod >> count5.publ_date >> count5.vacancy_name >> count5.salary >> count5.feasibility >> count5.post_cod >> count5.form_cod >> count5.LVL_cod;
    table5.push_back(count5);
    write_to_file_vacancy(table5, S5);
}
void Recruitment_agency::vacancy_rewrite()
{
    int num, i = 0;
    cout << "Введите код переписываемой вакансии: ";
    cin >> num;
    while(table5[i].vacancy_cod != num)
    {
        i++;
    }
    cout << "Изменяемая вакансия: " << endl;
    cout << table5[i].vacancy_cod << " " << table5[i].publ_date << " " << table5[i].vacancy_name << " " << table5[i].salary << " " << table5[i].feasibility << " " << table5[i].post_cod << " " <<table5[i].form_cod << " " << table5[i].LVL_cod << endl;
    cout << "Введите измененные параметры вакансии: " << endl;
    cin >> table5[i].vacancy_cod >> table5[i].publ_date >> table5[i].vacancy_name >> table5[i].salary >> table5[i].feasibility >> table5[i].post_cod >> table5[i].form_cod >> table5[i].LVL_cod;
    write_to_file_vacancy(table5, S5);
}
void Recruitment_agency::vacancy_menu()
{
add_to_vacancy_vector("vacancyin.txt");
int x = 0;

    do
    {
        cout << "ТАБЛИЦА: ВАКАНСИИ" << endl << endl;
        cout << "1. Вывести таблицу" << endl;
        cout << "2. Удаление вакансии" << endl;
        cout << "3. Добавление вакансии" << endl;
        cout << "4. Перезапись вакансии" << endl;
        cout << "5. Выход из таблицы" << endl;
        cout << endl;
        cin >> x;

        switch(x)
        {
            case 1: vacancy_write(); break;
            case 2: vacancy_delete(); break;
            case 3: vacancy_add(); break;
            case 4: vacancy_rewrite(); break;
            case 5: break;
            default: cout << "Неправильно введен пункт меню, от 1 до 5"; break;
        };
    }
    while(x != 5);
}
