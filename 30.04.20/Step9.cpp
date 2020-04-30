#include <iostream>
#include <cstring>

using namespace std;

int main()
{
string line;
getline(cin, line);
for(int i = 0; i != line.size(); i++)
{
	if(!ispunct(line[i]))
	cout << line[i];
}
return 0;
}