#include<iostream>
#include<string>
#include <algorithm>
#include <fstream>
#include <locale>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Rus");
    int k;
    char msg[80];
    ifstream in;
    in.open("input.txt");
    int i = 0;
    while(1)
    {
        char ch = in.get();
        if(in.eof())
        {
            break;
        }
        msg[i] = ch;
        i++;
    }
    in.close();
    cout << "\n¬ведите сдвиг:" << endl;
    cin >> k;
    for (int j = 0; j < i; j++)
    {
        if(msg[j] == 'z')
            msg[j] = 'a' + (k - 1);

        else if(msg[j] == 'Z')
            msg[j] = 'A' + (k - 1);

		else
            msg[j] = msg[j] + k;
    }
    ofstream of;
    of.open("out.txt");
    of << msg;
    of.close();
    return 0;
}
