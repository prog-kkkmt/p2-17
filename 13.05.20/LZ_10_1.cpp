#include <iostream>
#include <cstring>
#include <fstream>
#include <vector>

using namespace std;

class Movie_Class
{
private:
	struct Movie
	{
		int code;
		string Name;
		string Genre;
	};

	vector<Movie> movie;
	Movie tepmMovie;

	string File;

	void record_File(vector<Movie>& movie, string File)
	{
		ofstream file(File);

		for(int i = 0; i < movie.size(); i++)
			file << movie[i].code << " " << movie[i].Name << " " << movie[i].Genre << endl;

		file.close();
	}

public:
	Movie_Class(string F)
	{
		File = F;
		ifstream file(File);

		while(file >> tepmMovie.code >> tepmMovie.Name >> tepmMovie.Genre)
		{
			movie.push_back(tepmMovie);
		}

		file.close();
	}

	void list_Movie()
	{
		cout << "-----------------------------\n";
		cout << "ID\tName\tGenre\n";

		for(int i = 0; i < movie.size(); i++)
			cout << movie[i].code << "\t" << movie[i].Name << "\t" << movie[i].Genre << endl;

		cout << "-----------------------------\n";
		
	}

	void add_Movie()
	{
		cout << "Enter ID/Name/Genre Movie: \n";
		cin >> tepmMovie.code >> tepmMovie.Name >> tepmMovie.Genre;
		movie.push_back(tepmMovie);
		record_File(movie, File);
	}

	void rm_Movie()
	{
		int id, i = 0;
		cout << "Enter ID movie for removing: ";
		cin >> id;

		for(i; movie[i].code != id; i++);

		movie.erase(movie.begin() + i);

		record_File(movie, File);
	}

	void ed_Movie()
	{
		int id, i = 0;
		cout << "Enter ID movie for edit: ";
		cin >> id;

		for(i; movie[i].code != id; i++);

		cout << movie[i].code << "\t" << movie[i].Name << "\t" << movie[i].Genre << endl;
		cout << "Enter ID/Name/Genre Movie: \n";
		cin >> movie[i].code >> movie[i].Name >> movie[i].Genre;

		record_File(movie, File);
	}

};

int main()
{
	Movie_Class cinema("input.txt");

	int num = 0;

	do
	{
		cout << "\n1. List movie\n" << "2. Add Movie\n" << "3. Removal Movie\n" << "4. Edit Movie\n";
		cout << "5. Exit\n";
		cin >> num;

		switch(num)
		{
			case 1: 
				cinema.list_Movie();
					break;
			case 2: 
				cinema.add_Movie();
					break;
			case 3: 
				cinema.rm_Movie();
					break;
			case 4: 
				cinema.ed_Movie();
					break;
			case 5:
					break;
			default: 
				cout << "Unknown, repeat please!\n";
					break;
		};
	}
	while(num != 5);

	return 0;
}