#include <iostream>
#include <cstring>
#include <fstream>
#include <vector>

#include "Sale_Class.hpp"

using namespace std;

void funct_Sale()
{
	Sale_Class Sale("File/Sale.txt");

	int num = 0;

	do
	{
		cout << "\n1. List sale\n" << "2. Add sale\n" << "3. Removal sale\n" << "4. Edit sale\n";
		cout << "5. Sort sale\n6. Exit\n";
		cin >> num;

		switch(num)
		{
			case 1: 
				Sale.list_sale();
					break;
			case 2: 
				Sale.add_sale();
					break;
			case 3: 
				Sale.rm_sale();
					break;
			case 4: 
				Sale.ed_sale();
					break;
			case 5: 
				Sale.sort_Sale();
					break;
			case 6:
					break;
			default: 
				cout << "Unknown, repeat please!\n";
					break;
		};
	}
	while(num != 6);
}