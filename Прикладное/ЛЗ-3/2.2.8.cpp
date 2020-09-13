//Ќапишите рекурсивную функцию вычислени€ наибольшего общего делител€ двух положительных целых чисел.


unsigned gcd(unsigned a, unsigned b)
{
if(b==0)
return a;
return gcd(b,a%b);
}
