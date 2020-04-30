# П2-17 Филиппов Леонид
[22.04.2020](#22.04.2020)</br>
[23.04.2020](#23.04.2020)</br>
[24.04.2020](#24.04.2020)</br>
[25.04.2020](#25.04.2020)</br>
[27.04.2020](#27.04.2020)</br>
[28.04.2020](#28.04.2020)</br>
[29.04.2020](#29.04.2020)</br>
[30.04.2020](#30.04.2020)</br>
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
## <a name="28.04.2020">28.04.2020</a>
### Раздел 4.1
4.1.7
Свяжите следующие классы в иерархию наследования: Character (Персонаж), LongRange (Персонаж дальнего действия), Wizard (Маг), SwordsMan (Мечник), Archer (Лучник).
```C++
#include <string> // std::string

struct Character
{
    std::string const & name() const;
    unsigned health() const;
};

struct LongRange : Character
{
    std::string const & name() const;
    unsigned health() const;

    unsigned range() const;
};

struct SwordsMan : Character
{
    std::string const & name() const;
    unsigned health() const;

    unsigned strength() const;    
};

struct Wizard : LongRange
{
    std::string const & name() const;
    unsigned health() const;

    unsigned range() const;

    unsigned mana() const;
};

struct Archer : LongRange
{
    std::string const & name() const;
    unsigned health() const;

    unsigned range() const;

    unsigned accuracy() const;
};
```
4.1.9
В этом задании вам нужно реализовать функцию get_foo (сигнатура которой намерено не приводится в задании полностью, вам нужно подумать и вывести ее самостоятельно).
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
### Раздел 4.2
4.2.6
![Image alt](https://github.com/prog-kkkmt/p2-17/raw/Филиппов/images/4.2.6.png)
4.2.7
![Image alt](https://github.com/prog-kkkmt/p2-17/raw/Филиппов/images/4.2.7.png)
4.2.8
![Image alt](https://github.com/prog-kkkmt/p2-17/raw/Филиппов/images/4.2.8.png)
4.2.9
![Image alt](https://github.com/prog-kkkmt/p2-17/raw/Филиппов/images/4.2.9.png)
## <a name="29.04.2020">29.04.2020</a>
### ЛЗ 6. Решение задач по теме "Ссылки"
###### Упражнения раздела 2.5
1) Упражнение 2.24. Какие из следующих определений (если они есть) недопустимы? Почему? Как их исправить?
```C++
(a)int ival = 1.01;
(b)int &rvall = 1.01;
(с)int &rval2 = ival;
(d)const int &rval3 = 1;
```
Ответ: 
b, d - неправильные т.к. ссылки должны ссылаться на обьект

2) Упражнение 2.25. Какие из следующих присвоений (если они есть) являются недопустимыми 
(с учетом предыдущих определений)? Если таковые есть, объясните, почему.
```C++
(а)rva12 = 3.14159;
(b)rva12 = rva13;
(с)ival = rval3;
(d)rval3 = ival;
```
Ответ:
d - неправильное, т.к. rval3 константа и ей присвоено 1 а это r-value

3) Упражнение 2.26. В чем разница между определениями (а) и присвоениями (Ь)? 
Какие из них (если есть) недопустимы?
```C++
(a)int ival = 0;	(b)ival = ri;
const int &ri = 0;	ri = ival;
```
Ответ:
a недопустимо т.к. ссылку следует инициализировать обьектом

4) Упражнение 2.27. Что отобразит на экране следующий код?
```C++
int i, &ri = i; i = 5; ri = 10;
std::cout << i << " " << ri << std::endl;
```
Ответ:
10 10

###### Упражнения раздела 4.2.3
5) Упражнение 4.15. Укажите принципиальные различия между указателями и ссылками.

Ответ:
Указатель может быть переназначен любое количество раз, в то время как ссылка после привязки не может быть перемещена на другую ячейку памяти;
Нельзя получить адрес ссылки, как можно это делать с указателями;
Указатели могут указывать "в никуда" (быть равными NULL);
Не существует арифметики ссылок, в то время как существует арифметика указателей.

###### Упражнения раздела 7.2.2
6) Упражнение 7.7. Объясните различие между параметрами в следующих двух объявлениях.
```C++
void f(Т);
void f(Т&);
```
Ответ: В первом случае T используется копия значения в функции, а во втором случае используется адрес переменной 

7) Упражнение 7.8. Приведите пример случая, когда параметр должен быть ссылочным.
Приведите пример случая, когда параметр не должен быть ссылочным.

Ответ: 
a) Пример, когда параметр должен быть ссылочным.
```C++
void swap(int &а, int &b)
{
	int t;
	t = a;
	a = b;
	b = t;
}
```
b) Пример, когда параметр не должен быть ссылочным.
```C++
int summ(int a, int b)
{
	return a + b;
}
```
8) Упражнение 7.10. Следующая функция хоть и вполне допустима, но менее полезна,
чем могла бы быть. Выявите и устраните ограничения.
```C++ 
bool test(string& s) { return s.empty(); } 
```
Написать main для аргументации своего решения

Ответ:
Т.к. этот параметр определён как string&, то вызвать функцию test можно только для объекта класса string, так что
```C++
int main()
{
	cout << test("Hello world");
}
```
привело бы к ошибке.
Проблема в том, что данная функция получает свой строковый аргумент как простую неконстантную ссылку несмотря на то, что модифицировать этот параметр не нужно.
Исправленный код:
```C++ 
bool test(const string& s) { return s.empty(); } 
```
9) Упражнение 7.11. Когда ссылочные параметры должны быть константными? 
Какие проблемы могут возникнуть, если параметр является обычной ссылкой, 
а какие — если он является константной ссылкой?

Ответ:
Параметры, которые не изменяют значение соответствующего аргумента, должны быть константными ссылками.
Функции с обычной ссылкой нельзя передать символьный строковый литерал.
Одним из самых главных недостатков передачи по значению является то, что все аргументы, переданные по значению, копируются в параметры функции. 
Когда аргументами являются большие структуры или классы, то этот процесс может занять много времени.
## <a name="30.04.2020">30.04.2020</a>
### ЛЗ 9. Разработка программ со строками
###### Упражнения раздела 3.2.1
1) Упражнение 3.2. Что такое стандартный конструктор?</br>
Ответ: Это автоматически создаваемый конструктор, если программист не обьявил конструктор в классе

2) Упражнение 3.3. Назовите три способа инициализации объекта класса string.
Ответ:
```C++
string s1;
string s2(s1);
string s3("value");
```
3) Упражнение 3.4. Каковы значения переменных s и s2?
```C++
string s; 
int main() { 
	string s2;
}
```
Ответ: s1 и s2 - пустые строки

###### Упражнения раздела 3.2.2
4) Упражнение 3.5. Напишите программу, читающую со стандартного устройства ввода целые строки. 
Измените программу так, чтобы она читала отдельные слова.</br>
Ответ:
```C++
#include <iostream>
#include <string>

int main()
{
	std::string word;
	while(std::cin >> word)
		std::cout << word;
	return 0;
}
```
5) Упражнение 3.6. Объясните, как поступают с символами предваряющих пробелов при чтении данных 
в строковую переменную, когда используется функция getline().</br>
Ответ:
Функция getline() не игнорирует предваряющие пробелы

###### Упражнения раздела 3.2.4
6) Упражнение 3.7. Напишите программу, которая читает две строки и уведомляет, равны ли они, 
а если нет, какая из них больше. Измените программу так, чтобы она указывала, имеют ли строки 
одинаковую длину, и если нет, то какая из них длинней.</br>
Ответ:
```C++
#include <iostream>
#include <string>

int main()
{
	std::string s1, s2;
	std::cin >> s1 >> s2;
	std::cout << (s1.size() == s2.size() ? "They are equal" : (s1.size() > s2.size() ? "The first line is larger than the second" : "The second line is larger than the first"));
	return 0;
}
```
7) Упражнение 3.8. Напишите программу, способную читать строки со стандартного устройства ввода 
и соединять их в одну большую строку. Отобразите полученную строку. Измените программу так, чтобы 
отделить соседние введенные строки пробелами.</br>
Ответ:
```C++
#include <iostream>
#include <string>

int main()
{
	std::string s, res;
	while(getline(std::cin, s))
    	{
        	res += (s + ' ');
        	std::cout << "Result: " << res << std::endl;
    	}
	return 0;
}
```
8) Упражнение 3.9. Что делает следующая программа? Действительно ли она допустима? Если нет, то почему?
```C++
string s;
cout << s[0] << endl;
```
Ответ: Допустима, но т.к. строка s пустая - ничего не выведется.

9) Упражнение 3.10. Напишите программу поиска в строке знаков пунктуации. 
Программа должна позволить ввести символьную строку, содержащую знаки пунктуации, 
и вывести ту же строку, но уже без знаков пунктуации.</br>
Ответ:
```C++
#include <iostream>
#include <string>

int main()
{
    std::string s;
    getline(std::cin, s);
    for(int i = 0; i != s.size(); i++)
    {
        if(!ispunct(s[i]))
            std::cout << s[i];
    }
    return 0;
}
```
10) (Гусятинер Л.Б.) Изменить программу упражнения 3.10. так, чтобы входные данные поступали из файла input.txt,
а результат записывался в файл output.txt</br>
```C++
#include <iostream>
#include <string>
#include <fstream>

int main()
{
    std::string s;
    std::ifstream file("Input.txt");
    std::ofstream file2("output.txt");
    getline(file, s);
    for(int i = 0; i != s.size(); i++)
    {
        if(!ispunct(s[i]))
            file2 << s[i];
    }
    file.close();
    file2.close();
    return 0;
}
```
