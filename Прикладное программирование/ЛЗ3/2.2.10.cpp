#include <iostream>

using namespace std;

void qq()
{
int a = 0;
cin >> a;
if(a == 0)
return;
qq();
cout << a << " ";
}
int main()
{
qq();
return 0;
}
