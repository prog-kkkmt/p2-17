#include <iostream>

using namespace std;

class CPoint
{
private:
    int x;
    int y;
public:
    CPoint(int, int);
    void Prn();
};

CPoint::CPoint(int _x, int _y)
{
    x = _x;
    y = _y;
}
void CPoint::Prn()
{
    cout << "Dot (" << x << ", " << y << ")" << endl;
}

int main()
{
    CPoint A(3, 9);
    A.Prn();
    return 0;
}
