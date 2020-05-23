//Метод итераций для функции -x^2 + 2x + 5
#include <iostream>
#include <cmath>

int main()
{
    double x0, x1, eps;
    std::cout << "Input x0, x1, eps: ";
    std::cin >> x0 >> x1 >> eps;
    double res;
    do
    {
        x1 = (exp(log(x0)) + 5) / 2;
        res = fabs(x1 = x0);
    }while(res <= eps);
    std::cout << x0;
    return 0;
}
