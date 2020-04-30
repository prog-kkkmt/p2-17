#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

int main()
{
string line;

ifstream file1("input.txt");
ofstream file2("output.txt");

getline(file1, line);
for(int i = 0; i != line.size(); i++)
{
	if(!ispunct(line[i]))
	{
	cout << line[i];
	file2 << line[i];
	}
}

file1.close();
file2.close();
return 0;
}