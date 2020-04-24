#include <cstddef> // size_t
#include <cstring> // strlen, strcpy

struct String {
	String(const char *str = "");
	String(size_t n, char c);
	~String();


    /* Реализуйте этот метод. */
	void append(String &other) {
        size_t new_size = size + other.size;
        char *new_str = new char[new_size + 1];
        strcpy(new_str, str);
        strcpy(new_str + size, other.str);
        delete[] str;
        str = new_str;
        size = new_size;        
    }

	size_t size;
	char *str;
};