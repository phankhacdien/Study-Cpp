#include <iostream>

using namespace std;

struct Student
{
	char name[25];
	float math, physics, chemistry, total;
} st;

Student &f()
{
	return st;
}

int main()
{
	Student& h = f();	//tọa 1 biến tham hiếu kiểu Student và gán giá trị là hàm f, hàm f sẽ trả về tham chiếu đến st
	cout << "Enter name: ";
	cin.get(st.name, 25);
	cout << "Enter math, physics, chemistry scores: ";
	cin >> h.math >> h.physics >> h.chemistry;
	h.total = h.math + h.physics + h.chemistry;
	cout << endl << "Name: " << h.name;
	cout << endl << "Total scores: " << h.total << endl;
	return 1;
}