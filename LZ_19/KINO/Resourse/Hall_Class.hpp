#ifndef HALL_H
#define HALL_H

#include <iostream>
#include <cstring>
#include <fstream>
#include <vector>

using namespace std;

class Hall_Class
{
private:
	struct hall
	{
		int code;
		int size;
	};

	vector<hall> Hall;
	hall tepmHall;

	string File;

	void record_File(vector<hall>& Hall, string File)
	{
		ofstream file(File);

		for(int i = 0; i < Hall.size(); i++)
			file << Hall[i].code << " " << Hall[i].size << endl;

		file.close();
	}

public:
	Hall_Class(string F)
	{
		File = F;
		ifstream file(File);

		while(file >> tepmHall.code >> tepmHall.size)
		{
			Hall.push_back(tepmHall);
		}

		file.close();
	}

	void list_Hall()
	{
		cout << "-----------------------------\n";
		cout << "ID\tsize\n";

		for(int i = 0; i < Hall.size(); i++)
			cout << Hall[i].code << "\t" << Hall[i].size << "\t" << endl;

		cout << "-----------------------------\n";
		
	}

	void add_Hall()
	{
		cout << "Enter ID/size Hall: \n";
		cin >> tepmHall.code >> tepmHall.size;
		Hall.push_back(tepmHall);
		record_File(Hall, File);
	}

	void rm_Hall()
	{
		int id, i = 0;
		cout << "Enter ID Hall for removing: ";
		cin >> id;

		for(i; Hall[i].code != id; i++);

		Hall.erase(Hall.begin() + i);

		record_File(Hall, File);
	}

	void ed_Hall()
	{
		int id, i = 0;
		cout << "Enter ID Hall for edit: ";
		cin >> id;

		for(i; Hall[i].code != id; i++);

		cout << Hall[i].code << "\t" << Hall[i].size << endl;
		cout << "Enter ID/size/Genre Hall: \n";
		cin >> Hall[i].code >> Hall[i].size;

		record_File(Hall, File);
	}

	void sort_Hall()
	{
		for(int i = 1; i < Hall.size(); i++)
		{
			for(int j = 0; j < Hall.size() - i; j++)
			{
				if(Hall[j].code > Hall[j + 1].code)
				{
					tepmHall = Hall[j];
					Hall[j] = Hall[j + 1];
					Hall[j + 1] = tepmHall;
				}
			}
		}
		record_File(Hall, File);
	}
//Добавлена фунция выгрузки в HTML
	void record_html()
	{
		string filehtml;
		cout << "Enter name .html file: ";
		cin >> filehtml;
		ofstream file("File/" + filehtml + ".html");

		file << "ID|size <br>";
		for(int i = 0; i < Hall.size(); i++)
			file << "<br>" << Hall[i].code << " " << Hall[i].size << endl;

		cout << "Record complete\n";

		file.close();
	}
};

#endif