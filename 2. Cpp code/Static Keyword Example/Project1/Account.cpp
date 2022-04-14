#include "Account.h"
#include <iostream>

using namespace std;

void Account::display() {
	cout << this->accNo << " " << this->name << endl;
}
