#include <iostream>

using namespace std;

void DataEnter(double *a, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "Please enter the number no " << i + 1 << ": ";
		cin >> a[i];
	}
}

void Permutation(double& x, double& y)
{
	double temp = x;
	x = y;
	y = temp;
}

void Sort(double *a, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (a[i] > a[j])
			{
				Permutation(a[i], a[j]);
			}
		}
	}
}

int main()
{
	double x[100];
	int i, n;
	cout << "Enter size of array you wanna sort: "; cin >> n;
	DataEnter(x,n);
	Sort(x,n);
	for (int i = 0; i < n; i++)
	{
		printf("%0.1lf \n", x[i]);
	}
	return 0;
}