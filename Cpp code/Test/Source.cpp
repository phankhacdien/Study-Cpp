#include <iostream>

using namespace std;

class Matrix
{
public:
	Matrix(int n):
	matrix_sz(n)
	{
		MatrixINIT();
	}

	void ShowMatrix();
	int f();
private:
	int matrix_sz;
	void MatrixINIT();
	int** arr = new int* [matrix_sz];
	int count;
};

void Matrix::MatrixINIT()
{
	for (int i = 0; i < matrix_sz; i++)
	{
		arr[i] = new int[matrix_sz];
	}

	cout << "Please enter the matrix access: ";
	for (int x = 0; x < matrix_sz; x++)
	{
		for (int y = 0; y < matrix_sz; y++)
		{
			cout << "Enter martrix[" << x << "][" << y << "]: "; cin >> arr[y][x];
		}
	}
}

void Matrix::ShowMatrix()
{
	for (int x = 0; x < matrix_sz; x++)
	{
		for (int y = 0; y < matrix_sz; y++)
		{
			cout << arr[x][y];
		}
		cout << endl;
	}
}

int Matrix::f()
{
	// write your code here
	//int count;
	for (int x = 0; x < matrix_sz; x++)
	{
		for (int y = 0; y < matrix_sz; y++)
		{
			if (arr[x][y] != y * matrix_sz + x + 1) count++;
		}
	}
	return count;
}

int main()
{
	int n, rs;
	cout << "Enter size of the matrix: "; cin >> n;

	Matrix* test = new Matrix(n);
	test->ShowMatrix();
	rs = test->f();
	return 0;
}