#include <iostream>
#include <string>
#include <cctype>
#include <fstream>

using namespace std;

int main()
{
    string s;
    string s2;
    ifstream input("input.txt");
    getline(input, s);

    ofstream output("output.txt");
    for (int i = 0; i < s.length(); i++)
    {
        if (!(ispunct(s[i])))
        {
            output << s[i];
        }
    }
    return 0;
}
