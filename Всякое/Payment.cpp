#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <Windows.h>

class Payment
{
private:
	std::string surname, name, midname;
	int yearOfEmployment, workedInMonth, workingDaysInMonth, experience;
	double salary, surcharge, sum, heldSum, sumOnHand;
	double ndfl = 0.87;
public:
	Payment()
	{
		std::cout << "Введите ФИО через пробел.\n";
		std::cin >> surname >> name >> midname;

		std::cout << "Введите год поступления на работу.\n";
		std::cin >> yearOfEmployment;

		std::cout << "Введите оклад (целочисленное число).\n";
		std::cin >> salary;

		std::cout << "Введите процент надбавки (без знака %).\n";
		std::cin >> surcharge;

		std::cout << "Введите количество отработанных дней в месяце.\n";
		std::cin >> workedInMonth;

		std::cout << "Введите количество рабочих дней в месяце.\n";
		std::cin >> workingDaysInMonth;
		std::cout << std::endl;

		sum = heldSum = sumOnHand = experience = 0;
	}

	//Подсчёт стажа
	void Experience() //not Golden
	{
		experience = 2020 - yearOfEmployment;
	}

	//Подсчёт начисленной суммы
	void Sum()
	{
		sum = (salary * ((surcharge + 100) / 100)) / workingDaysInMonth * workedInMonth;
	}

	//Подчёт удержанной суммы
	void HeldSum()
	{
		heldSum = sum - sumOnHand;
	}

	//Подсчёт выданной на руки суммы
	void SumOnHand()
	{
		sumOnHand = sum * ndfl;
	}

	//Запись всех данных в файл
	void get()
	{
		std::ofstream file("output.txt");

		file << "Работник: " << surname << " " << name << " " << midname << "\n";
		file << "Стаж: " << experience;

		if (experience > 10 && experience < 20)
			file << " лет.\n";
		else
		{
			int x = experience % 10;
			if (x == 1)
				file << " год.\n";
			if (x > 1 && x < 5)
				file << " года.\n";
			if (x > 4 && x <= 9 || x == 0)
				file << " лет.\n";
		}

		file << std::fixed << std::setprecision(2) << "Начисленная сумма: " << sum << " рублей.\n";		
		file << std::fixed << std::setprecision(2) << "Удержанная сумма: " << heldSum << " рублей.\n";
		file << std::fixed << std::setprecision(2) << "Сумма, выданная на руки: " << sumOnHand << " рублей.\n";
		
		file.close();

		std::cout << "Запись в файл завершена.\n";
	}
};

int main()
{
	system("chcp 1251");
	std::cout << std::endl;

	Payment employee;
	employee.Experience();
	employee.Sum();
	employee.SumOnHand();
	employee.HeldSum();
	employee.get();

	return 0;
}
