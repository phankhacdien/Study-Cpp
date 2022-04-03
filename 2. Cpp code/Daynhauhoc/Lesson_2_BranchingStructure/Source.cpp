#include <iostream>
#include <Windows.h>

using namespace std;

int main()
{
	{
		char ch;
		cout << "Enter your full name";
		cin >> ch;

		system("cls");

		do
		{
			cout << ch;
			ch = cin.get();
			Sleep(1000);
		} while (ch != '\n' && ch != EOF);
		cout << endl;
	}
	return 0;
}