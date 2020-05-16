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
    CPoint *pB = NULL;
    pB = new CPoint;

    pB -> SetX(133);
    pB -> SetY(144);

    cout << "Dot with coordinats (" << pB->GetX() << ", " << pB->GetY() << ")" << endl;
    delete pB;
    return 0;
}


