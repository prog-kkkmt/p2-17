#include <iostream>

using namespace std;

int logorifm(int n)
{
    int p = 0, i = 1;
    for(int i = 1; i <= n; i*=2)
    {
        p++;
    }
    return p - 1;
}

int main()
{
    int T;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        int T2;
        cin >> T2;
        cout << logorifm(T2) << endl;
    }
    return 0;
}
