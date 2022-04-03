#include <iostream>
#include <iomanip>
#include <conio.h>
#include <math.h>

using namespace std;

double Squares(double x);
double Intergral(double (*f)(double) = Squares, double a = 0.0, double b = 1.0);

double Squares(double x)
{
	return x * x;
}

double Intergral(double (*f)(double), double a, double b)
{
	int n = 1000;
	double s = 0.0, h = (b - a) / n;
	for (int i = 0; i < n; i++)
	{
		s += f(a + i * h + h) + f(a + i * h);
		return s * h / 2;
	}
}

int main()
{
	system("cls");
	cout << setiosflags(ios::showpoint) << setprecision(2);
	cout << "Intergral from 0 to 1 of X^2 = " << Intergral() << endl;
	cout << "Intergral form 0 to 1 of exp(x) = " << Intergral(exp) << endl;
	cout << "Intergral form 0 to pi/2 of sin(x) = " << Intergral(sin, 0, 3.24 / 2) << endl;
	return 0;
}