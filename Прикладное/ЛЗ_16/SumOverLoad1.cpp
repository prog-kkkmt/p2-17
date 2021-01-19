#include <iostream>
#include <complex>

using namespace std;

void sum(int, int, int, int);
void sum(double, double, double, double);

void div(int, int, int, int);
void div(double, double, double, double);

void prod(int, int, int, int);
void prod(double, double, double, double);

void ABS(int, int);
void ABS(double, double);

void eq_gt(int, int, int, int);
void eq_gt(double, double, double, double);

int main()
{
	//Sum
	sum(4, 2, 4, 7);
	sum(2.6, 2.3, 4.1, 6.4);
	//Div
	div(23, 1, 3, 1);
	div(23.5, 1.2, 3.5, 1.5);
	//Prod
	prod(23, 1, 3, 1);
	prod(2.6, 2.3, 4.1, 6.4);
	//ABS
	ABS(-4, 5);
	ABS(-4.7, 5.2);
	//equal and graten
	eq_gt(2, 5, 2, 5);
	eq_gt(2.0, 5.3, 2.7, 6.5);

	return 0;
}

void sum(int a, int ai, int b, int bi)
{
	complex<int> z1(a, ai);
	complex<int> z2(b, bi);
	cout << "Sum int:\t"<< z1 + z2 << endl;
}

void sum(double a, double ai, double b, double bi)
{
	complex<double> z1(a, ai);
	complex<double> z2(b, bi);
	cout << "Sum double:\t" << z1 + z2 << endl;
}

void div(int a, int ai, int b, int bi)
{
	complex<int> z1(a, ai);
	complex<int> z2(b, bi);
	cout << "Div int:\t" << z1 / z2 << endl;
}

void div(double a, double ai, double b, double bi)
{
	complex<double> z1(a, ai);
	complex<double> z2(b, bi);
	cout << "Div double:\t" << z1 / z2 << endl;
}

void prod(int a, int ai, int b, int bi)
{
	complex<int> z1(a, ai);
	complex<int> z2(b, bi);
	cout << "Prod int:\t" << z1 * z2 << endl;
}

void prod(double a, double ai, double b, double bi)
{
	complex<double> z1(a, ai);
	complex<double> z2(b, bi);
	cout << "Prod double:\t" << z1 * z2 << endl;
}

void ABS(int a, int ai)
{
	complex<int> z(a, ai);
	cout << "ABS int:\t" << abs(z) << endl;
}

void ABS(double a, double ai)
{
	complex<double> z(a, ai);
	cout << "ABS double:\t" << abs(z) << endl;
}

void eq_gt(int a, int ai, int b, int bi)
{
	complex<int> z1(a, ai);
	complex<int> z2(b, bi);

	if(abs(z1) == abs(z2))
		cout << "Equal" << endl;
	else if(abs(z1) > abs(z2))
		cout << "z1 greater then z2" << endl;
	else
		cout << "z2 greater then z1" << endl;

}
void eq_gt(double a, double ai, double b, double bi)
{
	complex<double> z1(a, ai);
	complex<double> z2(b, bi);

	if(abs(z1) == abs(z2))
		cout << "Equal" << endl;
	else if(abs(z1) > abs(z2))
		cout << "z1 greater then z2" << endl;
	else
		cout << "z2 greater then z1" << endl;
}
