//Напишите программу, которая посимвольно читает из std::cin, пока не достигнет конца потока ввода,
//и заменяет несколько подряд идущих пробелов одним и выводит полученный результат в std::cout.


#include <iostream>
using namespace std;

int main()
{

char c = '\0';
bool boo = true;
while (cin.get(c))
{
if (c!=' ')
{
cout << c;
boo = true;
}
else if(boo)
{
cout << c;
boo = false;
}
}

return 0;
}
