#pragma once
#include <string>

using namespace std;

class Account {
private:
	int accNo;
	string name;

public:
	static int count;
	
	Account(int accNo, string name) {
		this->accNo = accNo;
		this->name = name;
		this->count++;
	}

	int getAccNo() {
		return this->accNo;
	}

	string getName() {
		return this->name;
	}

	void display();
};

