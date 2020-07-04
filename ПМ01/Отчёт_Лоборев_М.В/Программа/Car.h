#pragma once

class Car
{
public:
	int code;
	std::string brand;

	Car(int code, std::string brand)
	{
		this->code = code;
		this->brand = brand;
	}

	void Car_print()
	{
		std::cout << "Код автомобиля: " << code << ", марка машины: " << brand;
	}
};