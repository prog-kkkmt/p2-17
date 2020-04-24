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
