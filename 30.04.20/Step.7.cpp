#include <iostream>
#include <cstring>

using namespace std;


int main()
{
	string line, lineSum;
	while(getline(cin, line))
	{
		lineSum += line;
		lineSum += " ";
	}

	cout << endl << lineSum;
	return 0;
}