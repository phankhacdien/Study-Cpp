#include <iostream>

using namespace std;
int global_variable;

int main() {
	float local_variable1 = 1;

	// Define number of employees is local variable inside the main block
	int number_of_employees = 30;

	{
		float local_variable2 = 2;

		//access to local_variable 1
		local_variable1 = 11;

		//access to local varible 2
		std::cout << "local_variable 2: " << local_variable2 << endl;

		//Define another local variable same name with employees
		int number_of_employees = 10;
		std::cout << "Number of employees of the inner block: " << number_of_employees << endl;

	}
	//access to local_variable 1
	std::cout << "local_variable1: " << local_variable1 << endl;

	std::cout << "Number of employees of the the outer block: " << number_of_employees << endl;

	cout << "Enter a value to global variable: ";
	cin >> global_variable;
	cout << "Value of global variable is: " << global_variable;

	return 0;
}