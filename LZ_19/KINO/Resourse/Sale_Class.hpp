#ifndef MOVIE_H
#define MOVIE_H

#include <iostream>
#include <cstring>
#include <fstream>
#include <vector>

#define SIZE 100

using namespace std;

class Sale_Class
{
private:
	struct Sale
	{	
		int code_sale;
		int code_movie;
		int code_hall;
		int place;
		char *time;
		size_t len_time;
	};

	vector<Sale> sale;
	Sale tempSale;
	string File;
	char c_time[SIZE];

	void record_File()
	{
		ofstream file(File);

		for(int i = 0; i < sale.size(); i++)
			file << sale[i].code_sale << " " << sale[i].code_movie << " " << sale[i].code_hall << " " << sale[i].place << " " << sale[i].time << endl;

		file.close();
	}

	void CharToStruct()
	{
		tempSale.len_time = strlen(c_time) + 1;
		tempSale.time = new char[tempSale.len_time];
		strcpy(tempSale.time, c_time);
	}

public:

	Sale_Class(string F)
	{
		File = F;
		ifstream file(File);
		
		while(file >> tempSale.code_sale >> tempSale.code_movie >> tempSale.code_hall >> tempSale.place >> c_time)
		{
			CharToStruct();

			sale.push_back(tempSale);
			tempSale.len_time = 0;
		}

		file.close();
	}

	~Sale_Class()
	{
		for(int i = 0; i < sale.size(); i++)
		{
			sale[i].len_time = 0;
		}
		tempSale.len_time = 0;
	}
	void list_sale()
	{
		cout << "-----------------------------\n";
		cout << "ID Sale|ID Movie|ID Hall|Place|Time\n";

		for(int i = 0; i < sale.size(); i++)
		{
			cout << sale[i].code_sale << "\t" << sale[i].code_movie << "\t ";
			cout << sale[i].code_hall << "\t " << sale[i].place << "\t" << sale[i].time << endl;
		}
		cout << "-----------------------------\n";		
	}

	void add_sale()
	{
		cout << "Enter ID Sale, ID Movie, ID Hall, Place, Time: \n";
		cin >> tempSale.code_sale >> tempSale.code_movie >> tempSale.code_hall >> tempSale.place >> c_time;

		CharToStruct();

		sale.push_back(tempSale);

		record_File();
		//delete[] tempSale.time;
	}

	void rm_sale()
	{
		int id, i = 0;
		cout << "Enter ID sale for removing: ";
		cin >> id;

		for(i; sale[i].code_sale != id; i++);

		sale.erase(sale.begin() + i);

		record_File();
	}

	void ed_sale()
	{
		int id, i = 0;
		cout << "Enter ID sale for edit: ";
		cin >> id;

		for(i; sale[i].code_sale != id; i++);

		cout << sale[i].code_sale << "\t" << sale[i].code_movie << "\t";
		cout << sale[i].code_hall << "\t" << sale[i].place << "\t " << sale[i].time << endl;

		cout << "Enter ID Sale, ID Movie, ID Hall, Place ,Time: \n";
		cin >> sale[i].code_sale >> sale[i].code_movie >> sale[i].code_hall >> sale[i].place >> c_time;

		CharToStruct();

		sale[i].time = tempSale.time;

		record_File();
	}

	void sort_Sale()
	{
		for(int i = 1; i < sale.size(); i++)
		{
			for(int j = 0; j < sale.size() - i; j++)
			{
				if(sale[j].code_sale > sale[j + 1].code_sale)
				{
					tempSale = sale[j];
					sale[j] = sale[j + 1];
					sale[j + 1] = tempSale;
				}
			}
		}
		record_File();
	}
//Добавлена фунция выгрузки в HTML
	void record_html()
	{
		string filehtml;
		cout << "Enter name .html file: ";
		cin >> filehtml;
		ofstream file("File/" + filehtml + ".html");

		file << "ID Sale|ID Movie|ID Hall|Place|Time <br>";
		for(int i = 0; i < sale.size(); i++)
			file << "<br>" << sale[i].code_sale << " " << sale[i].code_movie << " " << sale[i].code_hall << " " << sale[i].place << " " << sale[i].time << endl;

		cout << "Record complete\n";

		file.close();
	}

};

#endif