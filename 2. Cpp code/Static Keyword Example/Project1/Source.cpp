#include <iostream>

using namespace std;

class Account {
public:
	int accNo;
	string name;
	static float rateOfInterest;

	Account(int accNo, string name) {
		this->accNo = accNo;
		this->name = name;
	}

	void display() {
		cout << accNo << " " << name << " " << rateOfInterest << endl;
	}
};

float Account::rateOfInterest = 6.8;

int main(void) {
	Account a1 = Account(201, "Phan Van Vinh");
	Account a2 = Account(202, "Dao Van Hoa");
	a1.display();
	a2.display();
	return 0;
}