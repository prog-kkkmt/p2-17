#pragma once

using namespace std;

class Hall
{
public:
    int hall_code;
    int seats;

    Hall(int hall_code, int seats)
    {
        this->hall_code = hall_code;
        this->seats = seats;
    }

    void hall_print()
    {
        cout << hall_code << " " << seats;
    }
};