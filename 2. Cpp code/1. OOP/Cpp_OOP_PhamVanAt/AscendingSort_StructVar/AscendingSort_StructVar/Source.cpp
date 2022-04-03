#include<iostream>

using namespace std;

struct Student
{
	char name[20];
	float math, physics, chemistry, total;
};

void InputStudent(Student *student, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "Student " << i + 1 << ": " << endl;
		cout << "Name: ";
		cin.ignore(1);
		cin.get(student[i].name, 20);
		cout << "Math, Physics, chemistry scores: ";
		cin >> student[i].math >> student[i].physics >> student[i].chemistry;
		student[i].total = student[i].math + student[i].physics + student[i].chemistry;
	}
}

void Swap(Student& st1, Student& st2)
{
	Student temp = st1;
	st1 = st2;
	st2 = temp;
}

void Sort(Student* st, int n)
{
	for (int i = 0; i < n-1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (st[i].total > st[j].total)
			{
				Swap(st[i], st[j]);
			}
		}
	}
}

void Show(Student* st, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "Student " << i + 1 << ": " << endl;
		cout << "Name: " << st[i].name << endl;
		cout << "Total Scores: " << st[i].total << endl;
	}
}

int main()
{
	Student LGIT[100];
	int n, i;
	system("cls");
	cout << "The number of LGIT student: "; cin >> n;
	InputStudent(LGIT, n);
	system("cls");
	Show(LGIT, n);
	cout << "=========== After sort ==============" << endl;
	Sort(LGIT, n);
	Show(LGIT, n);
	return 0;
}