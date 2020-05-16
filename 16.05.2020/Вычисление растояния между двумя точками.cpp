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
    int GetX()
    {
        return x;
    }
    int GetY()
    {
        return y;
    }
};

double length(CPoint p1, CPoint p2)
    {
        int x1, x2, y1, y2;
        double L;
        x1 = p1.GetX();
        y1 = p1.GetY();
        x2 = p2.GetX();
        y2 = p2.GetY();
        L = sqrt(pow(x2 - x1, 2.0) + pow(y2 - y1, 2.0));
    }
int main()
{
    CPoint p1(3, 0), p2(0, 4);
    cout << "Length = " << length(p1, p2);
    return 0;
}
