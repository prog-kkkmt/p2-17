#include <iostream>

using namespace std;

class CPoint
{
private:
    int *px;
    int *py;
public:
    CPoint(int x = 0, int y = 0);
    ~CPoint();
    void Prn();
};

CPoint::CPoint(int _x, int _y)
{
    px = new int;
    *px = _x;
    py = new int;
    *py = _y;
}
CPoint::~CPoint()
{
    delete px;
    delete py;
}
void CPoint::Prn()
{
    cout << "Dot (" << *px << ", " << *py << ")" << endl;
}

int main()
{
    CPoint A(3, 9), B;
    A.Prn();
    B.Prn();
    return 0;
}
