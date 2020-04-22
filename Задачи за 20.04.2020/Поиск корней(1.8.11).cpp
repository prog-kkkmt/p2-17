#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    double a, b, c, d, x1, x2;
    cin >> a >> b >> c;
    d = (b * b) - (4 * a * c);
    if(d == 0) //Åñëè äèñêðèìèíàíò = 0, áóäåò 1 êîðåíü.
    {
        x1 = (-b + sqrt(d)) / (2 * a);
        cout << x1 << " " << x1;
    }
    if(d > 0) //Åñëè äèñêðèìèíàíò > 0, áóäåò 2 êîðíÿ.
    {
        x1 = (-b + sqrt(d)) / (2 * a);
        x2 = (-b - sqrt(d)) / (2 * a);
        cout << x1 << " " << x2;
    }
    if(d < 0) //Åñëè äèñêðèìèíàíò ìåíüøå íóëÿ - íåò êîðíåé.
    {
        cout << "No real roots";
    }
}
