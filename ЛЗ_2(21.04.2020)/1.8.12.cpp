#include <iostream>
using namespace std;

int main()
{
    char a = '\0';
    bool flag = true;
    while (cin.get(a))
    {
        if (a!=' ')
        {
            cout << a;
            flag = true;
        }
        else if(flag)
        {
            cout << a;
            flag = false;
        }
    }
}
