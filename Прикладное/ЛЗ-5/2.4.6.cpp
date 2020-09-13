//Напишите функцию, которая вычисляет длину C-style строки. Учтите, что завершающий нулевой символ считать не нужно.

unsigned strlen(const char *str)
{
int i = 0;
while (str[i] != '\0')
i++;
return i;
}
