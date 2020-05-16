#include <iostream>
#include <cstring>
#include <fstream>
#include <vector>

#include "Resourse/cinema_Main.hpp"

using namespace std;

void AboutProgramm();

int main()
{
	int a = 0;
	do
	{
		
		cout << "1. Movie\n2. Hall\n3. Sale\n4.About program\n5.Exit\n";
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
		    	AboutProgramm();
		    		break;
			case 5: 
					break;
			default: 
				cout << "Unknown, repeat please!\n";
					break;
		}
	}
	while(a != 5);

	return 0;
}

void AboutProgramm()
{
	cout << "Make by student Strelnikov Sergey P2-17\n\n";
	cout << "Three tables about movie halls and tickets\n";
}