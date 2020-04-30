#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main()
{
    string s;
    getline(cin, s);
    for (int i = 0; i < s.length(); i++)
    {
        if (!(ispunct(s[i])))
            cout << s[i];
    }
    cout << endl;
    return 0;
}
