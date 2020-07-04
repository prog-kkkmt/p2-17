#pragma once

class Manager
{
public:
	int code;
	std::string name;

	Manager(int code, std::string name)
	{
		this->code = code;
		this->name = name;
	}

	void Manager_print()
	{
		std::cout << "Код менеджера: " << code << ", имя: " << name;
	}
};