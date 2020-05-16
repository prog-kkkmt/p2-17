#include <iostream>

using namespace std;

class CPoint
{
private:
    int x;
    int y;
public:
void SetX(int);

void SetY(int);

int GetX();

int GetY();

};
void CPoint::SetX(int _x)
{
    x = _x;
}
void CPoint::SetY(int _y)
{
    y = _y;
}
int CPoint::GetX()
{
    return x;
}
int CPoint::GetY()
{
    return y;
}


int main()
{
    CPoint A, *pA = &A;

    A.SetX(3);
    pA -> SetY(7);

    cout << "Dot with coordinats (" << A.GetX() << ", " << A.GetY() << ")" << endl;
    return 0;
}
