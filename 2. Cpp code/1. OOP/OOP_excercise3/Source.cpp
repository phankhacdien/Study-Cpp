#include <iostream>
#include < string>

using namespace std;

class Animal
{
public:
	Animal(string name, float age, string place) :
		name_(name), age_(age), place_(place)
	{}

	virtual void InfoDisp()
	{}
protected:
	string name_, place_;
	float age_;
};

class Zebra : public Animal
{
public:
	Zebra(string name, float age, string place) :
		Animal(name, age, place)
	{}

	void InfoDisp();
};

void Zebra::InfoDisp()
{
	cout << "Name: " << name_ << endl;
	cout << "Type: Zebra" << endl;
	cout << "Age: " << age_ << endl;
	cout << "Place of origin: " << place_ << endl;
}

class Dolphin : public Animal
{
public:
	Dolphin(string name, float age, string place) :
		Animal(name, age, place)
	{}

	void InfoDisp();
};

void Dolphin::InfoDisp()
{
	cout << "Name: " << name_ << endl;
	cout << "Type: Dolphin" << endl;
	cout << "Age: " << age_ << endl;
	cout << "Place of origin: " << place_ << endl;
}

int main()
{
	Animal* Tuan = new Zebra("Tuan", 23, "VietNam");
	Animal* Danh = new Dolphin("Danh", 22, "Sea");

	Tuan->InfoDisp();
	Danh->InfoDisp();
	return 0;
}