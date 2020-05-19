#include "Recruitment_agency.hpp"
void Recruitment_agency::write_to_file_posts(vector<posts>& table, string S)
    {
        ofstream of(S);
        for(int i = 0; i < table.size(); i++)
        {
            of << table[i].post_kod << " " << table[i].post_name << endl;
        }
        of.close();
    }
void Recruitment_agency::add_to_posts_vector(string S)
    {
        ifstream in(S);
        while(in >> count1.post_kod >> count1.post_name)
        {
            table.push_back(count1);
        }
        in.close();
    }
void Recruitment_agency::post_write()
{
    cout << "______________" << endl;
    for(int i = 0; i < table.size(); i++)
    {
        cout << "|" << table[i].post_kod << "| " << table[i].post_name << endl;
    }
    cout << "______________" << endl;
    cout << endl;
}
void Recruitment_agency::post_delete()
{
    int num, i = 0;
    cout << "Введите номер удаляемой должности: ";
    cin >> num;
    while(num != table[i].post_kod)
    {
        i++;
    }
    table.erase(table.begin() + i);
    write_to_file_posts(table, S);
}
void Recruitment_agency::post_add()
{
    cin >> count1.post_kod >> count1.post_name;
    table.push_back(count1);
    write_to_file_posts(table, S);
}
void Recruitment_agency::post_rewrite()
{
    int num, i = 0;
    cout << "Введите код изменяемой должности: ";
    cin >> num;
    while(table[i].post_kod != num)
    {
        i++;
    }
    cout << "Изменяемая должность: " << endl;
    cout << table[i].post_kod << " " << table[i].post_name << endl;
    cout << "Введите измененную должность: " << endl;
    cin >> table[i].post_name;
    write_to_file_posts(table, S);
}
void Recruitment_agency::post_menu()
{
    add_to_posts_vector("postsin.txt");
    int x = 0;

    do
    {
        cout << "ТАБЛИЦА: ДОЛЖНОСТИ" << endl << endl;
        cout << "1. Вывести таблицу" << endl;
        cout << "2. Удаление должности" << endl;
        cout << "3. Добавление должности" << endl;
        cout << "4. Перезапись должности" << endl;
        cout << "5. Выход из программы" << endl;
        cout << endl;
        cin >> x;

        switch(x)
        {
            case 1: post_write(); break;
            case 2: post_delete(); break;
            case 3: post_add(); break;
            case 4: post_rewrite(); break;
            case 5: break;
            default: cout << "Неправильно введен пункт меню, от 1 до 5"; break;
        };
    }
       while(x != 5);
}
