//Напишите программу, которая посимвольно читает из std::cin, пока не достигнет конца потока ввода, 
//и заменяет несколько подряд идущих пробелов одним и выводит полученный результат в std::cout.

#include <iostream>

int main()
{
    char c = '\0';
    bool boolmeni = true;

    while (std::cin.get(c))
    {
        if (c != ' ')
        {
            std::cout << c;
            boolmeni = true;
        }

        else if (boolmeni)
        {
            std::cout << c;
            boolmeni = false;
        }
    }

    return 0;
}