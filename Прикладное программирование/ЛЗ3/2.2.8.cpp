//Напишите рекурсивную функцию вычисления наибольшего общего делителя двух положительных целых чисел (Greatest Common Divisor, GCD). 
unsigned gcd(unsigned a, unsigned b)
{
if(b==0)
return a;
return gcd(b,a%b);
}
