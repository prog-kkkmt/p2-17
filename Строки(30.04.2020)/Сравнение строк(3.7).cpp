#include <iostream>
#include <string>
#include <locale>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Rus");
    string s;
    string s2;
    getline(cin, s);
    getline(cin, s2);
    if(s == s2)
    {
        cout << "Строки равны" << endl;
    }
    else if(s > s2)
    {
        cout << "Сторка s больше строки s2" << endl;
    }
    else if(s > s2)
    {
        cout << "Сторка s2 больше строки s" << endl;
    }
    return 0;
}
