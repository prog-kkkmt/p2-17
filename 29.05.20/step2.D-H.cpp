#include <iostream>

using namespace std;

int compute(int a, int m, int n)
{
    int r;
    int y = 1;

    while (m > 0)
    {
        r = m % 2;
        if (r == 1)
            y = (y*a) % n;
        a = a*a % n;
        m = m / 2;
    }
    return y;
}


int main()
{
    int p = 23;
    int g = 5;      

    int a, b;   
    int A, B; 


    a = 6;   
    A = compute(g, a, p);

    b = 15;   
    B = compute(g, b, p);

    int keyA = compute(B, a, p);
    int keyB = compute(A, b, p);

    cout << "Alice's Secret Key is " << keyA << "\nBob's Secret Key is " << keyB << endl;

    return 0;
}