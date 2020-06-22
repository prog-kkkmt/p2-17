#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
#include "Sipher.h"

int main()
{
    system("chcp 1251");
	system("cls");
    std::cout << "Выберите метод шифрования:" << std::endl;
    std::cout << "1. Шифр Цезаря." << std::endl;
	std::cout << "2. Морзе." << std::endl;
	std::cout << "3. Выход из программы." << std::endl;
    std::cout << "Ответ: ";

	Sipher oh_overlord;
	
    int choice;
    std::cin >> choice;
    switch (choice)
    {
    case 1:
		oh_overlord.CaesarEncryption(); break;
	case 2:
		oh_overlord.MorseEncryption();  break;
    case 3:
        exit(0);
    }

    std::cout << std::endl;
    system("pause");
}