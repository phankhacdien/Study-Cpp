#include <iostream>

using namespace std;

struct Student
{
	char name[25];
	float math, physics, chemistry, total;
};

Student* st;

void mallocError()
{
	cout << "Memory allocation error!";
	exit(0);
}

void InputStudent(int n)
{
	st = new Student[n + 1];
	set_new_handler(mallocError);
	for (int i = 0; i < n; i++)
	{
		Student& h = st[i];
		cout << "Student number " << i+1 << ": " << endl;
		cout << "Enter name: "; 
		cin.ignore(1);
		cin.get(h.name, 25);
		cout << "Enter math, physics, chemistry scores: "; cin >> h.math >> h.physics >> h.chemistry;
		h.total = h.math + h.physics + h.chemistry;
	}
}

Student& getStudent(int i, int n)
{
	if (i < 1 || i > n)
	{
		cout << "Number not valid!";
		exit(0);
	}
	return st[i];
}

int main()
{
	int n, i;
	cout << "Number of students: "; cin >> n;
	InputStudent(n);
	while (1)
	{
		cout << "Enter the student number you wanna show: "; cin >> i;
		Student& h = getStudent(i, n);
		cout << "Name: " << h.name;
		cout << "Total scores: " << h.total;
	}
	return 1;
}