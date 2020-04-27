#include <iostream>

using namespace std;

char *getline()
{
    const int n = 1;
    int len = n;
    int i = 0;

    char c;
    char *str = (char*) malloc (n * sizeof(char));

    while(cin.get(c) && c != '\n')
    {
        if(i == len)
        {
            str = (char*) realloc (str, len = len + n);
        }
        str[i++] = c;
    }
    char *rez = new char[i + 1];
    for(int j = 0; j < i; j++)
    {
        rez[j] = str[j];
    }
    free(str);
    return rez;
}
