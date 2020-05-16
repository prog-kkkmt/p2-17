#include <iostream>

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
    CPoint(const CPoint& p)
    {
        x = p.x;
        y = p.y;
    }
    void print()
    {
        cout << "Point (" << x << ", " << y << ")" << endl;
    }
};

int main()
{
    CPoint A(6, 7);
    CPoint B(A);

    A.print();
    B.print();
    return 0;
}
