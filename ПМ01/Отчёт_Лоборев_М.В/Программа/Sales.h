#pragma once

class Sales
{
public:
	int buyerCode, managerCode, carCode, price;
	std::string govNumber, date;

	Sales(int buyerCode, int managerCode, int carCode, int price, std::string govNumber, std::string date)
	{
		this->buyerCode = buyerCode;
		this->managerCode = managerCode;
		this->carCode = carCode;
		this->price = price;
		this->govNumber = govNumber;
		this->date = date;
	}

	void Sales_print()
	{
		std::cout << "Покупатель: " << buyerCode << ", менеджер: " << managerCode << ", автомобиль: " << carCode << ", цена: " << price << ", государственный номер: " << govNumber << ", дата покупки: " << date;
	}
};