# p2-17 Филиппов
[22.04.2020](#22.04.2020)
***
## <a name="твоё_название">22.04.2020</a>
### Раздел 2.3
2.3.9
В этой задаче нам нужно реализовать функцию, которая сдвигает содержимое массива влево на заданное число позиций (циклический сдвиг).
```C++
void rotate(int a[], unsigned size, int shift)
{
    if (shift > 0) {
        rotate (a, size, shift - 1);
        int tmp = a[0];
        for (int i = 0; i < size - 1; i++) 
            a[i] = a[i + 1];
        a[size-1] = tmp;
    }
}
```
### Раздел 2.4
2.4.6
В этой задаче нам нужно реализовать функцию strlen
```C++
unsigned strlen(const char *str)
{
    unsigned i = 0;
    while(str[i++] != '\0')
        ;
    return i - 1;
}
```
2.4.7
В этой задаче нам нужно реализовать функцию strcat
```C++
void strcat(char *to, const char *from)
{
  for (; *to; to++);
      for (; *from != '\0';)
        *to++ = *from++;
  *to++ = '\0';
}
```
2.4.8
В этой задаче нам нужно реализовать функцию strstr
```C++
int strstr(const char *text, const char *pattern)
{
    const char *i = text, *p = pattern;
    for (; *i && *p; ++i) {
        if (*i != *p) 
            p = pattern;
        if (*i == *p) 
            ++p;
    }
    return *p ? -1 : (i - text) - (p - pattern);
}
```
