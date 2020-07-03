#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "Hall.h"
#include "Film.h"
#include "Sale.h"
#include "Functions.h"

using namespace std;

int main()
{
    system("chcp 1251");
    system("cls");
    vector <Hall> Halls;
    vector <Film> Films;
    vector <Sale> Sales;

    read_file_hall(Halls);
    read_file_film(Films);
    read_file_sale(Sales);

    print_halls(Halls);
    print_films(Films);
    print_sales(Sales);

    popular_genre(Films);
    fullnes(Halls, Sales);
}

