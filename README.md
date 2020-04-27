# П2-17 Филиппов Леонид
[22.04.2020](#22.04.2020)</br>
[23.04.2020](#23.04.2020)</br>
[24.04.2020](#24.04.2020)</br>
[25.04.2020](#25.04.2020)</br>
[27.04.2020](#27.04.2020)</br>
***
## <a name="22.04.2020">22.04.2020</a>
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
## <a name="23.04.2020">23.04.2020</a>
### Раздел 2.6
2.6.9
В этой задаче вам нужно реализовать функцию resize.
```C++
char *resize(const char *str, unsigned size, unsigned new_size)
{
  char *new_str = new char[new_size];
  for (int i = 0; i < size && i < new_size; ++i)
      new_str[i] = str[i];
  delete[] str;
  return new_str;
}
```
2.6.10
В этой задаче вам нужно реализовать функцию getline.
```C++
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
```
### Раздел 2.7
2.7.9
В этой задаче вам нужно реализовать функцию транспонирования матрицы.
```C++
int ** transpose(const int * const * m, unsigned rows, unsigned cols)
{
    int **matrix = new int *[cols];
    matrix[0] = new int[rows * cols];
    for (int i = 1; i < cols; ++i)
    {
        matrix[i] = matrix[i - 1] + rows;
    }

    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            matrix[j][i] = m[i][j];
        }
    }
    return matrix;    
}
```
2.7.10
В этой задаче вам нужно реализовать функцию swap_min, которая принимает на вход двумерный массив целых чисел, ищет в этом массиве строку, содержащую наименьшее среди всех элементов массива значение, и меняет эту строку местами с первой строкой массива.
```C++
void swap_min(int *m[], unsigned rows, unsigned cols)
{
    int min = m[0][0], num;
    for(int i = 0; i < rows; i++)
        for(int j = 0; j < cols; j++)
            if(min > m[i][j])
            {
                num = i;
                min = m[i][j];
            }
    int *tmp = m[num];
    m[num] = m[0];
    m[0] = tmp;
}
```
## <a name="24.04.2020">24.04.2020</a>
### Раздел 3.1
3.1.6
![Image alt](https://github.com/prog-kkkmt/p2-17/raw/Филиппов/images/3.1.6.png)
3.1.7
![Image alt](https://github.com/prog-kkkmt/p2-17/raw/Филиппов/images/3.1.7.png)
3.1.8
![Image alt](https://github.com/prog-kkkmt/p2-17/raw/Филиппов/images/3.1.8.png)
### Раздел 3.3
3.3.10
В этой задаче требуется реализовать конструктор, который принимает на вход C-style строку, вычисляет ее размер и сохраняет его в поле size, кроме того, конструктор должен аллоцировать память достаточную для хранения копии переданной строки, копирует переданную строку в выделенную память и сохраняет указатель на начало этой области памяти в поле str. 
```C++
#include <cstddef> // size_t
#include <cstring> // strlen, strcpy

struct String {

    /* Реализуйте этот конструктор */
	String(const char *str = "") : size(strlen(str))
    {
        this->size = strlen(str);
        this->str = new char[size + 1];
        strcpy(this->str, str);
    }
	size_t size;
	char *str;
};
```
3.3.11
В этой задаче требуется реализовать заполняющий конструктор принимает число и символ, и создает строку с заданным количеством повторений переданного символа.
```C++
#include <cstddef> // size_t
#include <cstring> // strlen, strcpy

struct String {

    /* Реализуйте этот конструктор */
	String(size_t n, char c)
    {
        this->size = n;
        this->str = new char[size + 1];
        for(size_t i = 0; i != size; i++)
            this->str[i] = c;
        this->str[size + 1] = '\0';
    }

    /* и деструктор */
	~String()
    {
        delete[] str;
    }


	size_t size;
	char *str;
};
```
3.3.12
В этой задаче требуется реализовать метод append.
```C++
#include <cstddef> // size_t
#include <cstring> // strlen, strcpy

struct String {
	String(const char *str = "");
	String(size_t n, char c);
	~String();


    /* Реализуйте этот метод. */
	void append(String &other)
    {
        char *str = new char[size + other.size + 1];
        strcpy(str, this->str);
        strcpy(str + size, other.str);
        delete[] this->str;
        this->str = str;
        this->size = size + other.size;
    }

	size_t size;
	char *str;
};
```
## <a name="25.04.2020">25.04.2020</a>
### Раздел 3.5
3.5.7
Реализовать несколько функций, которые дают полный доступ к полям, несмотря на то, что они закрытые.
```C++
/*
 * Класс Cls определен точно таким образом:
 *
 * struct Cls {
 * Cls(char c, double d, int i);
 * private:
 *     char c;
 *     double d;
 *     int i;
 * };
 *
 */

// Эта функция должна предоставить доступ к полю c объекта cls.
// Обратите внимание, что возвращается ссылка на char, т. е.
// доступ предоставляется на чтение и запись.
char &get_c(Cls &cls) {
    return *(char*)(&cls);
}

// Эта функция должна предоставить доступ к полю d объекта cls.
// Обратите внимание, что возвращается ссылка на double, т. е.
// доступ предоставляется на чтение и запись.
double &get_d(Cls &cls) {
    return *(double*)((char*)(&cls) + 8);
}

// Эта функция должна предоставить доступ к полю i объекта cls.
// Обратите внимание, что возвращается ссылка на int, т. е.
// доступ предоставляется на чтение и запись.
int &get_i(Cls &cls) {
    return *(int*)((char*)(&cls) + 16);
}
```
### Раздел 3.6
3.6.6
![Image alt](https://github.com/prog-kkkmt/p2-17/raw/Филиппов/images/3.6.6.png)
3.6.12
![Image alt](https://github.com/prog-kkkmt/p2-17/raw/Филиппов/images/3.6.12.png)
## <a name="27.04.2020">27.04.2020</a>
### Раздел 3.7
3.7.9
![Image alt](https://github.com/prog-kkkmt/p2-17/raw/Филиппов/images/3.7.9.png)
3.7.10
Добавить в класс String реализацию конструктора копирования.
```C++
#include <cstddef> // size_t
#include <cstring> // strlen, strcpy

struct String {
	String(const char *str = "");
	String(size_t n, char c);
	~String();


    /* Реализуйте конструктор копирования */
	String(const String &other): String() 
    {
        append(other);        
    }


	void append(const String &other);

	size_t size;
	char *str;
};
```
3.7.11
Завершить класс String, добавив к нему оператор присваивания.
```C++
#include <algorithm> // std::swap
#include <cstddef>   // size_t
#include <cstring>   // strlen, strcpy

struct String {
	String(const char *str = "");
	String(size_t n, char c);
	String(const String &other);
	~String();

    void swap(String& other)
    {
        std::swap(size, other.size);
        std::swap(str, other.str);
    }

	String &operator=(const String &other)
    {
        if(this != &other)
            String(other).swap(*this);
        return *this;
    }

	void append(const String &other);

	size_t size;
	char *str;
};
```
3.7.12
![Image alt](https://github.com/prog-kkkmt/p2-17/raw/Филиппов/images/3.7.12.png)
