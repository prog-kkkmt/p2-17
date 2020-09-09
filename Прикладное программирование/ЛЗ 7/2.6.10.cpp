#include <iostream>

char *resize(const char *str, unsigned size, unsigned new_size)
{
char *ns = new char [new_size];
int i = 0;
while (i<size && i<new_size)
{
ns[i] = str[i];
i++;
}
delete[] str;
return(ns);
}


char *getline()
{
int i = 0, buf = 40;
char c, *str = new char [buf];

while (std::cin.get(c) && c != '\n')
{
if (i == buf)
str = resize(str, i, buf += buf);
str[i] = c;
i++;
}
str[i] = '\0';
return str;
}
