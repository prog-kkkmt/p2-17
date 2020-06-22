#pragma once

class Sipher
{
public:
	void CaesarEncryption()
	{
		system("cls");

		std::string message;
		char ch;
		int key;

		std::ifstream filein("Unencrypted_message.txt");
		std::getline(filein, message);
		filein.close();

		if (message.size() == 0)
		{
			std::cout << "Не обнаружена строка в файле Unencrypted_message.txt\n\n";
			system("pause");
			exit(0);
		}

	wrongKey:
		std::cout << "Введите ключ шифра от 1 до 5: ";
		std::cin >> key;
		if (key >= 1 && key <= 5)
		{
			for (int i = 0; message[i] != '\0'; ++i)
			{
				ch = message[i];
				if (ch >= 'a' && ch <= 'z')
				{
					ch = ch + key;
					if (ch > 'z')
					{
						ch = ch - 'z' + 'a' - 1;
					}
					message[i] = ch;
				}
				else if (ch >= 'A' && ch <= 'Z')
				{
					ch = ch + key;
					if (ch > 'Z')
					{
						ch = ch - 'Z' + 'A' - 1;
					}
					message[i] = ch;
				}
			}
		}
		else
		{
			std::cout << "Неверный ключ. Значение не должно выходить за заданные рамки..\n";
			system("pause");
			system("cls");
			std::cin.clear();
			std::cin.ignore(32767, '\n');
			goto wrongKey;
		}

		system("cls");
		std::cout << "Сообщение зашифровано в файл Encrypted_message.txt\n";

		std::ofstream fileout("Encrypted_message.txt");
		fileout << message;
	}

	void MorseEncryption()
	{
		system("cls");

		std::string message;
		char ch;

		std::ifstream filein("Unencrypted_message.txt");
		std::getline(filein, message);
		filein.close();

		if (message.size() == 0)
		{
			std::cout << "Не обнаружена строка в файле Unencrypted_message.txt\n\n";
			system("pause");
			exit(0);
		}

		std::ofstream fileout("Encrypted_message.txt");
		std::cout << "Сообщение зашифровано в файл Encrypted_message.txt\n";

		for (int i = 0; message[i] != '\0'; ++i)
		{
			ch = message[i];

			if (ch >= 'a' && ch <= 'z')
			{
				switch (ch)
				{
				case 'a':
					fileout << ".- ";    break;
				case 'b':
					fileout << "-... ";  break;
				case 'c':
					fileout << "-.-. ";  break;
				case 'd':
					fileout << "-.. ";   break;
				case 'e':
					fileout << ". ";     break;
				case 'f':
					fileout << "..-. ";  break;
				case 'g':
					fileout << "--. ";   break;
				case 'h':
					fileout << ".... ";  break;
				case 'i':
					fileout << ".. ";    break;
				case 'j':
					fileout << ".--- ";  break;
				case 'k':
					fileout << "-.- ";   break;
				case 'l':
					fileout << ".-.. ";  break;
				case 'm':
					fileout << "-- ";    break;
				case 'n':
					fileout << "-. ";    break;
				case 'o':
					fileout << "--- ";   break;
				case 'p':
					fileout << ".--. ";  break;
				case 'q':
					fileout << "--.- ";  break;
				case 'r':
					fileout << ".-. ";   break;
				case 's':
					fileout << "... ";   break;
				case 't':
					fileout << "- ";     break;
				case 'u':
					fileout << "..- ";   break;
				case 'v':
					fileout << "...- ";  break;
				case 'w':
					fileout << ".-- ";   break;
				case 'x':
					fileout << "-..- ";  break;
				case 'y':
					fileout << "-.-- ";  break;
				case 'z':
					fileout << "--.. ";  break;
				}
			}
			else if (ch >= 'A' && ch <= 'Z')
			{
				switch (ch)
				{
				case 'A':
					fileout << ".- ";    break;
				case 'B':
					fileout << "-... ";  break;
				case 'C':
					fileout << "-.-. ";  break;
				case 'D':
					fileout << "-.. ";   break;
				case 'E':
					fileout << ". ";     break;
				case 'F':
					fileout << "..-. ";  break;
				case 'G':
					fileout << "--. ";   break;
				case 'H':
					fileout << ".... ";  break;
				case 'I':
					fileout << ".. ";    break;
				case 'J':
					fileout << ".--- ";  break;
				case 'K':
					fileout << "-.- ";   break;
				case 'L':
					fileout << ".-.. ";  break;
				case 'M':
					fileout << "-- ";    break;
				case 'N':
					fileout << "-. ";     break;
				case 'O':
					fileout << "--- ";   break;
				case 'P':
					fileout << ".--. ";  break;
				case 'Q':
					fileout << "--.- ";  break;
				case 'R':
					fileout << ".-. ";   break;
				case 'S':
					fileout << "... ";   break;
				case 'T':
					fileout << "- ";     break;
				case 'U':
					fileout << "..- ";   break;
				case 'V':
					fileout << "...- ";  break;
				case 'W':
					fileout << ".-- ";   break;
				case 'X':
					fileout << "-..- ";  break;
				case 'Y':
					fileout << "-.-- ";  break;
				case 'Z':
					fileout << "--.. ";  break;
				}
			}
			else if (ch >= '0' && ch <= '9')
			{
				switch (ch)
				{
				case '1':
					fileout << ".---- "; break;
				case '2':
					fileout << "..--- "; break;
				case '3':
					fileout << "...-- "; break;
				case '4':
					fileout << "....- "; break;
				case '5':
					fileout << "..... "; break;
				case '6':
					fileout << "-.... "; break;
				case '7':
					fileout << "--... "; break;
				case '8':
					fileout << "---.. "; break;
				case '9':
					fileout << "----. "; break;
				case '0':
					fileout << "----- "; break;
				}
			}
			else if (ch == ' ')
				fileout << "   ";
		}
	}
};
