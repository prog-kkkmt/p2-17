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
