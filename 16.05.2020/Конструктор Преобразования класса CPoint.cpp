#include <iostream>
#include <math.h>

using namespace std;

class CPoint
{
private:
    int x;
    int y;
public:
    CPoint(int _x, int _y)
    {
        x = _x;
        y = _y;
    }
    CPoint()
    {
        x = y = 0;
    }
    CPoint(int a)
    {
        x = y = a;
    }
    void print()
    {
        cout << "Dot (" << x << ", " << y << ")" << endl;
    }
};

int main()
{
    CPoint p1 = 5;
    CPoint A(3, 9);
    CPoint B;
    p1.print();
    A.print();
    B.print();
    return 0;
}
