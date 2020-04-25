#include <iostream>
#include <locale>

using namespace std;

void zapoln_mass(int a[], int n)
{
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
}

int max_elem(int a[], int n)
{
    int i = 0;
    int max = a[i];
    for(i = 1; i < n; i++)
    {
        if(a[i] > max)
        {
            max = a[i];
        }
    }
    cout << max;
}

int summ_elem(int a[], int n)
{
    int s = 0;
    for(int i = 0; i < n; i++)
    {
        s = s + a[i];
    }
    cout << s;
}

int print_mass(int a[], int n)
{
    for(int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}

int main()
{
    setlocale(LC_ALL, "Rus");
    int n;
    cout << "Введите кол-во элементов в массиве: ";
    cin >> n;
    cout << endl;
    int a[n];
    int st;
    cout << "Пункты меню" << endl;
    cout << "1) Ввести массив" << endl;
    cout << "2) Найти максимальный элемент массива" << endl;
    cout << "3) Найти сумму элементов массива" << endl;
    cout << "4) Напечатать информацию" << endl;
    cout << "5) Выход" << endl << endl;
    cout << "Введите номер меню: ";
    cin >> st;

    switch(st)
    {
        case 1: zapoln_mass(a, n); break;
        case 2: max_elem(a, n); break;
        case 3: summ_elem(a, n); break;
        case 4: print_mass(a, n); break;
        case 5: return 0; break;
    }
    return 0;
}
