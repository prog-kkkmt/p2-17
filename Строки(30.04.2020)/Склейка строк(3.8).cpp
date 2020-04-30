#include <iostream>
#include <string>
#include <locale>

using namespace std;

int main()
{
    string s, s2;
        while(getline(cin, s) && s != "0")
        {
            s2 = s2 + s + " ";
        }
    cout << s2;
    return 0;
}
