#include <iostream>
#include <cmath>

using namespace std;

int main() 
{
	{
		// unary operator
		int value;

		cout << "Enter the value: ";
		cin >> value;

		cout << "Use unary plus operator: " << +value << endl;
		cout << "Use unary minus operator: " << -value << endl;
	}

	{
		// binary operator
		int x, y;
		cout << "Enter value to x and y: ";
		cin >> x >> y;

		cout << x << "+" << y << "=" << x + y << endl;
		cout << x << "-" << y << "=" << x - y << endl;
		cout << x << "*" << y << "=" << x * y << endl;
		cout << x << "/" << y << "=" << static_cast<float>(x) / (float)y << endl;
		cout << x << "%" << y << "=" << x % y << endl;
	}

	{
		// cmath library
		int x, y;

		cout << "Enter value to x, y: ";
		cin >> x, y;

		cout << x << "^" << y << pow(2, 3) << endl;
		cout << "Square root of x: " << sqrt(x) << endl;
	}
	
	return 0;

}