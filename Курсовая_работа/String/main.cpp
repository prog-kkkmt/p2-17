#include "string.cpp"

using namespace std;

// Функция для отображения меню
int menu(String &s)
{
    int choice;
    cout << "\n1) Проверка на пустую строку" << endl;
    cout << "2) Конкатенация строк" << endl;
    cout << "3) Сравнение строк" << endl;
    cout << "4) Присвоить строку" << endl;
    cout << "5) Получить длину строки" << endl;
    cout << "6) Выход" << endl;
    cin >> choice;
    // Очитска буфера
    cin.clear();
    cin.ignore(32767, '\n');
    // Меню выбора действий со строкой
        switch(choice)
        {
        case 1:
            cout << (s.is_empty() == 0 ? "Не пустая" : "Пустая") << endl; 	//Проверка на пустоту
            break;
    // Конкатенация строк
        case 2:
        {
            String f;
            cout << "Введите строку с которой хотите сложить: ";
            cin >> f;
            s += f;
            cout << s;
            break;
        }
    // Сравнение строк
        case 3:
        {
            cout << "Введите строку с которой хотите сравнить: ";
            String s2;
            cin >> s2;
            cout << (s == s2 ? "Равны" : "Не равны") << endl;
            break;
        }
    // Присвоение строк
        case 4:
        {
            cout << "Введите строку к которой хотите присвоить: ";
            String s2;
            cin >> s2;
            s = s2;
            cout << s;
            break;
        }
    // Вывод длины строки
        case 5:
            cout << s.getLength() << endl;
            break;
    // Выход из программы
        case 6:
            return 0;
        default:
            menu(s);
            break;
        }
        menu(s);
}
// Главное тело программы
int main()
{
    setlocale(LC_ALL, "Russian");
    String s;
    cout << "Введите строку: ";
    cin >> s;
    menu(s);
    return 0;
}

