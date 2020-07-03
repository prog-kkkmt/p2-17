#pragma once

using namespace std;

class Film
{
public:
    int film_code;
    string name;
    string genre;

    Film(int film_code, string name, string genre)
    {
        this->film_code = film_code;
        this->name = name;
        this->genre = genre;

    }

    void film_print()
    {
        cout << film_code << " " << name << " " << genre;
    }
};