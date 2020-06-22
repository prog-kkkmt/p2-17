#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
#include "Sipher.h"

int main()
{
	//Изменение кодировки проекта на Windows 1251
	system("chcp 1251");
	system("cls");
	std::cout << "Выберите метод шифрования:" << std::endl;
	std::cout << "1. Шифр Цезаря." << std::endl;
	std::cout << "2. Морзе." << std::endl;
	std::cout << "3. Выход из программы." << std::endl;
	std::cout << "Ответ: ";

	//Авторская переменная
	Sipher mloborev;
	
	//Выбор метода шифрования
	int choice;
	std::cin >> choice;
	switch (choice)
	{
		case 1:
			mloborev.CaesarEncryption(); break;
		case 2:
			mloborev.MorseEncryption();  break;
		case 3:
			exit(0);
    }
	
	std::cout << std::endl;
	system("pause");
	exit(0);
}
