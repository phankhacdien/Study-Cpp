#include <iostream>

using namespace std;

class Mother
{
public:
	virtual void Display()
	{
		cout << "This is mother class." << endl;
	}
};

class Daughter : public Mother
{
public:
	void Display()
	{
		cout << "This is daughter class." << endl;
	}
};

int main()
{
	Mother* girl = new Daughter();
	girl->Display();
	return 0;
}