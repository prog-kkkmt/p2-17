#include <cstddef> // size_t
#include <cstring> // strlen, strcpy

struct String {

    /* Реализуйте этот конструктор */
	String(size_t n, char c)
    {
        this->size = n;
        this->str = new char[size+1];
        for (int i = 0; i<size; i++)
            str[i] = c;
        str[size+1] = '\0';
    }

    /* и деструктор */
	~String()
    {
        delete [] str;
    }


	size_t size;
	char *str;
};
