//Метод половинного деления для функции -x^2 + 2x + 5
#include <iostream>
#include <cmath>

double func(double x)
{
    return -1 * x * x + 2 * x + 5;
}

void calculation(double (*f)(double))
{
    double a, b, eps;
    std::cout << "Input x, y, eps: ";
    std::cin >> a >> b >> eps;
    double res;
    do
    {
        res = (a + b) / 2;
        if (f(res) * f(b))
            a = res;
        else
            b = res;
    } while (fabs(a - b) <= eps);
    std::cout << a << std::endl;
}

int main()
{
    calculation(func);
    return 0;
}

