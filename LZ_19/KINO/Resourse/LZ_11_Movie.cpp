#include <iostream>
#include <cstring>
#include <fstream>
#include <vector>

#include "Movie_Class.hpp"

using namespace std;

void funct_Movie()
{
	Movie_Class cinema("File/Movie.txt");

	int num = 0;

	do
	{
		cout << "\n1. List movie\n" << "2. Add Movie\n" << "3. Removal Movie\n" << "4. Edit Movie\n";
		cout << "5. Sort movie\n6. Record HTML\n7. Exit\n";
		cin >> num;

		switch(num)
		{
			case 1: 
				cinema.list_Movie();
					break;
			case 2: 
				cinema.add_Movie();
					break;
			case 3: 
				cinema.rm_Movie();
					break;
			case 4: 
				cinema.ed_Movie();
					break;
			case 5:
				cinema.sort_Movie();
					break;
			case 6://Добавлена фунция выгрузки в HTML
				cinema.record_html();
					break;
			case 7: 
					break;
			default: 
				cout << "Unknown, repeat please!\n";
					break;
		};
	}
	while(num != 7);
}