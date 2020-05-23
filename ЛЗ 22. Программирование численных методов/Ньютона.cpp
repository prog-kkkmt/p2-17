//Метод Ньютона для функции -x^2 + 2x + 5
#include <iostream>
#include <cmath>

double f_func(double x)
{
    return -1 * x * x + 2 * x + 5;
}

double df_func(double x)
{
    return -2 * x + 2;
}

int main()
{
    double x, eps;
    std::cout << "Input x, eps: ";
    std::cin >> x >> eps;
    double f, df;
    do
    {
        f = f_func(x);
        df = df_func(x);
        x -= f / df;
    }
    while(fabs(f) > eps);
    std::cout << x;
    return 0;
}
