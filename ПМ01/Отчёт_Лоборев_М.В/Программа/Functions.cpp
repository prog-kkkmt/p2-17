#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <iomanip>
#include "Buyer.h"
#include "Manager.h"
#include "Car.h"
#include "Sales.h"

void readFileBuyer(std::vector <Buyer>& buyer)
{
	int code;
	std::string name;

	std::ifstream file("buyer.txt");

	if (!file.is_open())
	{
		std::cout << "Файл buyer.txt не найден.\n";
		exit(0);
	}

	while (file >> code >> name)
		buyer.push_back(Buyer(code, name));
	file.close();
}

void readFileManager(std::vector <Manager>& manager)
{
	int code;
	std::string name;

	std::ifstream file("manager.txt");

	if (!file.is_open())
	{
		std::cout << "Файл manager.txt не найден.\n";
		exit(0);
	}

	while (file >> code >> name)
		manager.push_back(Manager(code, name));
	file.close();
}

void readFileCar(std::vector <Car>& car)
{
	int code;
	std::string brand;

	std::ifstream file("car.txt");

	if (!file.is_open())
	{
		std::cout << "Файл car.txt не найден.\n";
		exit(0);
	}

	while (file >> code >> brand)
		car.push_back(Car(code, brand));
	file.close();
}

void readFileSales(std::vector <Sales>& sales)
{
	int buyerCode, managerCode, carCode, price;
	std::string govNumber, date;

	std::ifstream file("sales.txt");

	if (!file.is_open())
	{
		std::cout << "Файл sales.txt не найден.\n";
		exit(0);
	}

	while (file >> buyerCode >> managerCode >> carCode >> price >> govNumber >> date)
		sales.push_back(Sales(buyerCode, managerCode, carCode, price, govNumber, date));
	file.close();
}

void averageTransactionAmount(std::vector <Sales>& sales)
{
	double buff = 0;

	for (int i = 0; i < sales.size(); i++)
	{
		buff += sales[i].price;
	}

	std::cout << "Средняя сумма сделки: " << buff / sales.size() << std::endl;
}

void EachCarSold(std::vector <Sales>& sales, std::vector <Car>& car)
{
	for (int i = 0; i < car.size(); i++)
	{
		int sum = 0;
		for (int j = 0; j < sales.size(); j++)
		{
			if (car[i].code == sales[j].carCode)
				sum += 1;
		}
		std::cout << "Доля продажи автомобиля " << car[i].brand << " составила: " << sum / (double)sales.size() * 100 << " процентов" << std::endl;
	}
}