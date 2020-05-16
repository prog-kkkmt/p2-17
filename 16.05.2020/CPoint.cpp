#include <iostream>

using namespace std;

class CPoint
{
private:
    int x;
    int y;
public:
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

int main()
{
    CPoint A, *bA = &A;

    A.SetX(3);
    bA -> SetY(8);

    cout << "Dot with coordinats (" << A.GetX() << ", " << A.GetY() << ")" << endl;
    return 0;
}
