#include <iostream>
#include <cstring>
#include <fstream>
#include <vector>

#include "Hall_Class.hpp"

using namespace std;

void funct_Hall()
{
	Hall_Class cinema("File/Hall.txt");
	int num = 0;

	do
	{
		cout << "\n1. List Hall\n" << "2. Add Hall\n" << "3. Removal Hall\n" << "4. Edit Hall\n";
		cout << "5. Sort Hall\n6. Record HTML\n7. Exit\n";
		cin >> num;

		switch(num)
		{
			case 1: 
				cinema.list_Hall();
					break;
			case 2: 
				cinema.add_Hall();
					break;
			case 3: 
				cinema.rm_Hall();
					break;
			case 4: 
				cinema.ed_Hall();
					break;
			case 5: 
				cinema.sort_Hall();
					break;
			case 6: //Добавлена фунция выгрузки в HTML
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