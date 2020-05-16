//При вводе 1 2 3 выводит 333

#include <iostream>
#include <vector>

using namespace std;


struct str
{
    size_t len;
    char *a = new char[len];
};

int main()
{
    vector<str>v;
    str tempV;

    cin >> tempV.a;
    v.push_back(tempV);

    cin >> tempV.a;
    v.push_back(tempV);

    cin >> tempV.a;
    v.push_back(tempV);

    cout << v[0].a << v[1].a << v[2].a;

    return 0;
}
