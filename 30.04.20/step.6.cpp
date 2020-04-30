#include <iostream>
#include <cstring>

using namespace std;


int main()
{
	string line1, line2;
	getline(cin, line1);
	getline(cin, line2);

	if(line1 == line2)
		cout << "Equal";
	else if(line1 > line2)
		cout << "Line 1 more";
	else if(line1 < line2)
		cout << "Line 2 more";
	return 0;
}