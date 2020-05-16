#ifndef MOVIE_H
#define MOVIE_H

#include <iostream>
#include <cstring>
#include <fstream>
#include <vector>

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
		string time;
	};

	vector<Sale> sale;
	Sale tepmSale;

	string File;

	void record_File(vector<Sale>& sale, string File)
	{
		ofstream file(File);

		for(int i = 0; i < sale.size(); i++)
			file << sale[i].code_sale << " " << sale[i].code_movie << " " << sale[i].code_hall << " " << sale[i].place << " " << sale[i].time << endl;

		file.close();
	}

public:
	Sale_Class(string F)
	{
		File = F;
		ifstream file(File);

		while(file >> tepmSale.code_sale >> tepmSale.code_movie >> tepmSale.code_hall >> tepmSale.place >> tepmSale.time)
		{
			sale.push_back(tepmSale);
		}

		file.close();
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
		cout << "Enter ID Sale, ID Movie, ID Hall, Place ,Time: \n";
		cin >> tepmSale.code_sale >> tepmSale.code_movie >> tepmSale.code_hall >> tepmSale.place >> tepmSale.time;
		sale.push_back(tepmSale);
		record_File(sale, File);
	}

	void rm_sale()
	{
		int id, i = 0;
		cout << "Enter ID sale for removing: ";
		cin >> id;

		for(i; sale[i].code_sale != id; i++);

		sale.erase(sale.begin() + i);

		record_File(sale, File);
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
		cin >> sale[i].code_sale >> sale[i].code_movie >> sale[i].code_hall >> sale[i].place >> sale[i].time;

		record_File(sale, File);
	}

	void sort_Sale()
	{
		for(int i = 1; i < sale.size(); i++)
		{
			for(int j = 0; j < sale.size() - i; j++)
			{
				if(sale[j].code_sale > sale[j + 1].code_sale)
				{
					tepmSale = sale[j];
					sale[j] = sale[j + 1];
					sale[j + 1] = tepmSale;
				}
			}
		}
		record_File(sale, File);
	}

};

#endif