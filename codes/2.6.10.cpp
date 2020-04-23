#include <iostream>

char *resize(const char *str, unsigned size, unsigned new_size)
{
  char *new_str = new char[new_size];
  for (int i = 0; i < size && i < new_size; ++i)
      new_str[i] = str[i];
  delete[] str;
  return new_str;
}


char *getline()
{
    int buf = 50, i = 0;
    char *str = new char[buf], c;
    while(std::cin.get(c) && c != '\n')
    {
        if(i == buf)
            str = resize(str, buf, buf += 50);
        str[i++] = c;
    }
    str[i] = '\0';
    return str;
}
