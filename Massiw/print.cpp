#include <iostream>

using namespace std;

void print(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << (i < n-1 ? ", " : "\n");
    }
}

