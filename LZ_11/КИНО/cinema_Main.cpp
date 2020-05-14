#include <iostream>
#include <cstring>
#include <fstream>
#include <vector>

#include "Resourse/cinema_Main.hpp"

using namespace std;

int main()
{
	int a = 0;
	do
	{
		
		cout << "1. Movie\n2. Hall\n3. Sale\n4.Exit\n";
		cin >> a;
		switch(a)
		{
			case 1: 
				funct_Movie();
					break;
			case 2: 
				funct_Hall();
					break;
			case 3: 
				funct_Sale();
					break;
			case 4: 
					break;
			default: 
				cout << "Unknown, repeat please!\n";
					break;
		}
	}
	while(a != 4);

	return 0;
}