#include <iostream>

char* getline(){
    char *str = new char[1024000], *ptr(str);
    while(std::cin.get(*ptr) && *ptr!='\n') ptr++;
    *(ptr+1) = '\0';
    return str;
}