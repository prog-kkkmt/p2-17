#include <iostream>
#include <string>

void encript(std::string& str, int k)
{
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] >= 'a' && str[i] <= 'z')
            str[i] = ((str[i] - 'a' + k) % 26) + 'a';
        if (str[i] >= 'A' && str[i] <= 'Z')
            str[i] = ((str[i] - 'A' + k) % 26) + 'A';
    }
    std::cout << str << std::endl;
}

void decript(std::string& str, int k)
{
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] >= 'a' && str[i] <= 'z')
            str[i] = ((str[i] - 'a' - k) % 26) + 'a';
        if (str[i] >= 'A' && str[i] <= 'Z')
            str[i] = ((str[i] - 'A' - k) % 26) + 'A';
    }
    std::cout << str << std::endl;
}

int main()
{
    std::string str; int k;
    std::cin >> str >> k;
    std::cout << "Encoded string: \n";
    encript(str, k);
    std::cout << "Unencoded string: \n";
    decript(str, k);
}
