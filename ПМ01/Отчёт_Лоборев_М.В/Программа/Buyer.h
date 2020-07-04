#pragma once

class Buyer
{
public:
	int code;
	std::string name;

	Buyer(int code, std::string name)
	{
		this->code = code;
		this->name = name;
	}

	void Buyer_print()
	{
		std::cout << "Код покупателя: " << code << ", имя: " << name;
	}
};