//Вам требуется написать программу, которая "переворачивает" последовательность положительных целых чисел. 
//На вход подается последовательность разделенных пробелами положительных целых чисел. Последовательность заканчивается нулем. 
//Требуется вывести эту последовательность в обратном порядке.
//На выводе числа нужно так же разделить пробелами. 
//Завершающий ноль — это просто индикатор конца последовательности, он не является ее частью, т.е. выводить его не нужно.
#include <iostream>

using namespace std;

void qq()
{
int a = 0;
cin >> a;
if(a == 0)
return;
qq();
cout << a << " ";
}
int main()
{
qq();
return 0;
}
