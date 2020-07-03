#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Hall.h"
#include "Film.h"
#include "Sale.h"

using namespace std;

void read_file_hall(vector <Hall>& Halls)
{
    int hall_code;
    int seats;
    ifstream infile("halls.txt");
    while (infile >> hall_code >> seats)
        Halls.push_back(Hall(hall_code, seats));
    infile.close();
}

void read_file_film(vector <Film>& Films)
{
    int film_code;
    string name;
    string genre;
    ifstream infile("films.txt");
    while (infile >> film_code >> name >> genre)
        Films.push_back(Film(film_code, name, genre));
    infile.close();
}

void read_file_sale(vector <Sale>& Sales)
{
    int sale_code;
    int film_code;
    int hall_code;
    string time;
    int seat_num;
    ifstream infile("sales.txt");
    while (infile >> sale_code >> film_code >> hall_code >> time >> seat_num)
        Sales.push_back(Sale(sale_code, film_code, hall_code, time, seat_num));
    infile.close();
}

void print_halls(vector <Hall>& Halls)
{
    cout << "Залы\n";
    for (int i = 0; i < Halls.size(); i++)
    {
        Halls[i].hall_print();
        cout << "\n";
    }
    cout << "\n";
}

void print_films(vector <Film>& Films)
{
    cout << "Фильмы\n";
    for (int i = 0; i < Films.size(); i++)
    {
        Films[i].film_print();
        cout << "\n";
    }
    cout << "\n";
}

void print_sales(vector <Sale>& Sales)
{
    cout << "Продажи\n";
    for (int i = 0; i < Sales.size(); i++)
    {
        Sales[i].sale_print();
        cout << "\n";
    }
    cout << "\n";
}

void popular_genre(vector <Film>& Films)
{
    int maxcount = 0;
    int g = 0;
    for (int i = 0; i < Films.size(); i++)
    {
        int count = 0;
        for (int j = 1; j < Films.size(); j++)
        {
            if (Films[i].genre == Films[j].genre);
            {
                count++;
            }
        }
        if (maxcount < count)
        {
            maxcount = count;
            g = i;
        }
    }
    cout << "Популярный жанр: " << Films[g].genre << endl;

}

void fullnes(vector <Hall>& Halls, vector <Sale>& Sales)
{
    for (int i = 0; i < Halls.size(); i++)
    {
        int sum = 0;
        for (int j = 0; j < Sales.size(); j++)
        {
            if (Halls[i].hall_code == Sales[j].hall_code)
                sum += 1;
        }
        cout << "\nУ зала с кодом " << Halls[i].hall_code
            << " наполненность: " << ((double)sum / Halls[i].seats) * 100;
    }
    cout << endl;
}