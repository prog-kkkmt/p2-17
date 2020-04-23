//Напишите программу для вычисления целочисленного логарифма по основанию 2. 
//На вход программе в первой строке подается число TT, далее следует TT строк с тестами.

#include <iostream>

int main()
{
    int t, p;
    std::cin >> t;

    for (int i = 0; i < t; i++)
    {
        std::cin >> p;
        int count = 0;
        int a = 2;
        
        while (a <= p)
        {
            a *= 2;
            count++;
        }
        
        std::cout << count << std::endl;
    }

    return 0;
}