#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <iomanip>
#include "Buyer.h"
#include "Manager.h"
#include "Car.h"
#include "Sales.h"
#include "Functions.h"

int main()
{
	system("chcp 1251");
	system("cls");

	std::vector <Buyer> buyer;
	std::vector <Manager> manager;
	std::vector <Car> car;
	std::vector <Sales> sales;

	readFileBuyer(buyer);
	readFileManager(manager);
	readFileCar(car);
	readFileSales(sales);

	for (int i = 0; i < buyer.size(); i++)
	{
		buyer[i].Buyer_print();
		std::cout << "\n";
	}

	std::cout << "\n";

	for (int i = 0; i < manager.size(); i++)
	{
		manager[i].Manager_print();
		std::cout << "\n";
	}

	std::cout << "\n";

	for (int i = 0; i < car.size(); i++)
	{
		car[i].Car_print();
		std::cout << "\n";
	}

	std::cout << "\n";

	for (int i = 0; i < sales.size(); i++)
	{
		sales[i].Sales_print();
		std::cout << "\n";
	}

	std::cout << "\n";

	averageTransactionAmount(sales);

	std::cout << "\n";

	EachCarSold(sales, car);
}