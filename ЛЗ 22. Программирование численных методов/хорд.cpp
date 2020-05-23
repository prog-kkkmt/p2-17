//Метод хорд для функции -x^2 + 2x + 5
#include <iostream>
#include <cmath>

double func(double x)
{
    return -1 * x * x + 2 * x + 5;
}

int main()
{
    double x0, x1, eps;
    std::cout << "Input x0, x1, eps: ";
    std::cin >> x0, x1, eps;
    double res = x1, sch;
    do
    {
        sch = func(res);
        res = (res - sch) / (sch - func(x0)) * (res - x0);
    }
    while(sch > eps);
    std::cout << res;
    return 0;
}
