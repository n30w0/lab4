#include "pch.h"
#include <iostream>
#include <math.h>
#include "tilt.h"
using namespace std;
Complex y(double);
int main()
{
	Complex ex1(5.2, -8);
	Complex ex2 = 4;
	Complex ex3;

	cout << "ex1 = " << ex1 << endl;
	cout << "ex2 = " << ex2 << endl;
	cout << "ex3 = " << ex3 << endl;
	cout << endl;

	ex3 = ex1 + ex2;
	ex1 /= ex3;
	ex2 *= ex3;

	cout << "ex3 = ex1 + ex2 = " << ex3 << endl;
	cout << "ex1 = ex1 / ex3 = " << ex1 << endl;
	cout << "ex2 = ex2 * ex3 = " << ex2 << endl;
	cout << endl;

	cout << "Vvedite deistvitel'nuyu i mnimuyu chast' kompleksnogo chisla:" << endl;
	cin >> ex3;
	cout << "ex3 = " << ex3 << endl;

	system("pause");	
}

Complex y(double z)
{
	return Complex(z*sinh(1+z), 1);
}