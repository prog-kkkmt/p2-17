#ifndef MOVIE_H
#define MOVIE_H

#include <iostream>
#include <cstring>
#include <fstream>
#include <vector>

#define SIZE 100

using namespace std;

class Movie_Class
{
private:
	struct Movie
	{
		int code;
		char *Name;
		size_t len_name;
		char *Genre;
		size_t len_genre;
	};

	vector<Movie> movie;
	Movie tempMovie;
	char c_name[SIZE];
	char c_genre[SIZE];
	string File;


	void record_File()
	{
		ofstream file(File);

		for(int i = 0; i < movie.size(); i++)
			file << movie[i].code << " " << movie[i].Name << " " << movie[i].Genre << endl;

		file.close();
	}

	void CharToStruct()
	{
		tempMovie.len_genre = strlen(c_name) + 1;
		tempMovie.Name = new char[tempMovie.len_genre];
		strcpy(tempMovie.Name, c_name);

		tempMovie.len_genre = strlen(c_genre) + 1;
		tempMovie.Genre = new char[tempMovie.len_genre];
		strcpy(tempMovie.Genre, c_genre);
	}

public:
	Movie_Class(string F)
	{
		File = F;
		ifstream file(File);

		while(file >> tempMovie.code >> c_name >> c_genre)
		{
			CharToStruct();
			movie.push_back(tempMovie);
		}

		file.close();
	}

	~Movie_Class()
	{
		for(int i = 0; i < movie.size(); i++)
		{
			movie[i].len_name = 0;
			movie[i].len_genre = 0;
		}
		tempMovie.len_name = 0;
		tempMovie.len_genre = 0;
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
		cin >> tempMovie.code >> c_name >> c_genre;

		CharToStruct();

		movie.push_back(tempMovie);
		record_File();
	}

	void rm_Movie()
	{
		int id, i = 0;
		cout << "Enter ID movie for removing: ";
		cin >> id;

		for(i; movie[i].code != id; i++);

		movie.erase(movie.begin() + i);

		record_File();
	}

	void ed_Movie()
	{
		int id, i = 0;
		cout << "Enter ID movie for edit: ";
		cin >> id;

		for(i; movie[i].code != id; i++);

		cout << movie[i].code << "\t" << movie[i].Name << "\t" << movie[i].Genre << endl;
		cout << "Enter ID/Name/Genre Movie: \n";
		cin >> movie[i].code >> c_name >> c_genre;

		CharToStruct();

		movie[i].Name = tempMovie.Name;
		movie[i].Genre = tempMovie.Genre;

		record_File();
	}

	void sort_Movie()
	{
		for(int i = 1; i < movie.size(); i++)
		{
			for(int j = 0; j < movie.size() - i; j++)
			{
				if(movie[j].code > movie[j + 1].code)
				{
					tempMovie = movie[j];
					movie[j] = movie[j + 1];
					movie[j + 1] = tempMovie;
				}
			}
		}
		record_File();
	}

};

#endif