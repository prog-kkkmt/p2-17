#include <iostream>

using namespace std;

int max_elementl(int *p, int *q)
{
    int max1 = *p;
    for(; p != q; p++)
    {
        if(*p > max1)
        {
            max1 = *p;
        }
    }
    return max1;

}

int main()
{
    int n;
    cin >> n;
    int m[10];
    int max1;
    for(int i = 0; i < n; i++)
    {
        cin >> m[i];
    }
    max1 = max_elementl(m, m + n);
    cout << max1;
    return 0;
}
