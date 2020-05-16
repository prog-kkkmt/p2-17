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
        x = 0;
        y = 0;
    }
    void SetX(int _x)
    {
        x = _x;
    }
    void SetY(int _y)
    {
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
    double square(CPoint *mas)
    {
        double L1, L2, L3, p;
        L1 = length(mas[0], mas[1]);
        L2 = length(mas[1], mas[2]);
        L1 = length(mas[2], mas[0]);
        p = (L1 + L2 + L3) / 2.0;
        if(p * (p - L1) * (p - L2) * (p - L3) >= 0)
        {
            return sqrt(p * (p - L1) * (p - L2) * (p - L3));
        }
        else
        {
            cout << "ERROR  Triangle" << endl;
            return -1;
        }
    }
    int main()
    {
        CPoint mas[3];
        int x, y;
        for(int i = 0; i < 3; i++)
        {
            cin >> x >> y;
            mas[i].SetX(x);
            mas[i].SetY(y);
        }
        cout << "S = " << square(mas) << endl;
        return 0;
    }
