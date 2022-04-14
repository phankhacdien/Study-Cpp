#include <iostream>
#include "Account.h"

using namespace std;

int Account::count = 0;

int main(void) {
	Account a1 = Account(201, "Phan Van Vinh");
	Account a2 = Account(202, "Dao Van Hoa");
	Account a3 = Account(203, "Tran Van Phu");

	a1.display();
	a2.display();
	a3.display();

	cout << "\nTong cac doi tuong la: " << Account::count << endl;
	return 0;
}