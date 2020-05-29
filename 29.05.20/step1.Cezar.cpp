#include <iostream>
#include <cstring>

using namespace std;

void skr(string &str, int a)
{
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] >= 'a' && str[i] <= 'z')
            str[i] = ((str[i] - 'a' + a) % 26) + 'a';
        
        if (str[i] >= 'A' && str[i] <= 'Z')
            str[i] = ((str[i] - 'A' + a) % 26) + 'A';
    }
    cout << str << endl;
}

void deskr(string &str, int a)
{
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] >= 'a' && str[i] <= 'z')
            str[i] = ((str[i] - 'a' - a) % 26) + 'a';

        if (str[i] >= 'A' && str[i] <= 'Z')
            str[i] = ((str[i] - 'A' - a) % 26) + 'A';
    }
    cout << str << endl;
}

int main()
{
    string str;
    int a;
    cin >> a >> str;

    cout << "Encoded str: \n";
    skr(str, a);

    cout << "Unencoded str: \n";
    deskr(str, a);
}