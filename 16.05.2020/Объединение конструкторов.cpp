#include <iostream>

using namespace std;

class CPoint
{
public:
    CPoint(int x = 0, int y = 0);
CPoint::CPoint(int  _x, int _y)
{
    x = _x;
    y = _y;
}
void Prn()
{
    cout << "Dot (" << x << ", " << y << ")" << endl;
}
};

int main()
{
    CPoint A;
    CPoint B(123, 432);

    A.Prn();
    B.Prn();
    return 0;
}
