#include <iostream>
#include <cstring>
#include <fstream>
#include <vector>

using namespace std;

class Movie
{
private:
	vector<string> Name;
	vector<string> Genre;
	vector<int> code;

	int c;
	string N;
	string G;
	string Name_File;

public:
	Movie(string Name_Inp)
	{
		Name_File = Name_Inp;
		ifstream file(Name_File);

 		while(file >> c >> N >> G)
 		{
 			//cout << c << N << G << endl;
 			code.push_back(c);						
 			Name.push_back(N);						
 			Genre.push_back(G);							
 		}
 		file.close();
	}

	void List()
	{
		cout << "--------------------------------\n";
		cout << "number/ID/name/Genre\n";
		for(int i = 0; i < code.size(); i++)
		{
			cout << i+1 << ". " << code[i] << " " << Name[i] << " " << Genre[i] << endl;
		}
		cout << "--------------------------------\n";
	}

	void add_Movie()
	{
		ofstream file(Name_File, ios::app);
		cout << "Enter ID/name/Genre\n";
		cin >> c >> N >> G;
		file << c << " " << N << " " << G << endl;
		code.push_back(c);						
 		Name.push_back(N);						
 		Genre.push_back(G);	

 		file.close();
	} 

	void del_Movie()
	{
		cout << "Enter ID Movie\n";
		int code_del;
		int i = 0;
		cin >> code_del;
	
		for(int i = 0; i < code.size(); i++)
		{
			if(code[i] == code_del)
			{
				code.erase(code.begin() + i);						
 				Name.erase(Name.begin() + i);						
 				Genre.erase(Genre.begin() + i);
 			}
 		}

 		ofstream file(Name_File);
 		for(int i = 0; i < code.size(); i++)
		{
			file << code[i] << " " << Name[i] << " " << Genre[i] << endl;
		}

		file.close();
	}

	void red_Movie()
	{
		int code_red;
		cout << "Enter ID Movie\n";
		cin >> code_red;
		cin >> c >> N >> G;

		for(int i = 0; i < code.size(); i++)
		{
			if(code[i] == code_red)
			{
				code[i] = c;
				Name[i] = N;
				Genre[i] = G;
			}
		}


		ofstream file(Name_File);
 		for(int i = 0; i < code.size(); i++)
		{
			file << code[i] << " " << Name[i] << " " << Genre[i] << endl;
		}

		file.close();
	}


};

int main()
{
	Movie p("input.txt");

	int ct;

	do
	{
		
		cout << "\n1. list\n" << "2. add Movie\n" << "3. del Movie\n" << "4. red Movie\n";
		cout << "5. Exit\n";
		cin >> ct;

		if(ct == 1)
			p.List();
		else if(ct == 2)
			p.add_Movie();
		else if(ct == 3)
			p.del_Movie();
		else if(ct == 4)
			p.red_Movie();
	}
	while(ct != 5);

	return 0;
}
