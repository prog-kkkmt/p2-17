#pragma once

using namespace std;

class Sale
{
public:
    int sale_code;
    int film_code;
    int hall_code;
    string time;
    int seat_num;

    Sale(int sale_code, int film_code, int hall_code, string time, int seat_num)
    {
        this->sale_code = sale_code;
        this->film_code = film_code;
        this->hall_code = hall_code;
        this->time = time;
        this->seat_num = seat_num;
    }

    void sale_print()
    {
        cout << sale_code << " " << film_code << " " << hall_code << " " << time << " " << seat_num;
    }
};