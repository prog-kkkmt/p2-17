#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string Cezar(string a, int step)
{
    string TC;
    for(int i = 0; i < a.length(); i++)
        TC = TC + (char)(a[i] + step);
    return TC;
}

string UnCezar(string TC, int step)
{
    string UnTC;
    for(int i = 0; i < TC.length(); i++)
        UnTC = UnTC + (char)(TC[i] - step);
    return UnTC;
}

int main()
{
    int step;
    cout << "Step: ";
    cin >> step;
    ifstream in ("input.txt");
    string a;
    getline(in, a);
    string TC = Cezar(a, step);
    cout << "Original: \n" << a << "\n";
    string UnTC = UnCezar(TC, step);
    cout << "Original (Cezar): \n" << TC << "\n";
    cout << "UnCezar: \n" << UnTC << "\n";
    ofstream out("output.txt");
    out << TC;
    in.close();
    out.close();
return 0;
}
