#include <iostream>
#include "Account.h"
#include "Programmer.h"
#include "Dog.h"

using namespace std;

int main() {
	Programmer p1;

	cout << "Salary: " << p1.salary << endl;
	cout << "Bonus: " << p1.bonus << endl;

	Dog d1;
	d1.eat();
	d1.bark();

	return 0;
}