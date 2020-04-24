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
