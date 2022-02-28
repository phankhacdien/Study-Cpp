#include <iostream>

using namespace std;

int main()
{
	int row_nums, col_nums;
	int Arr2D[20][20];

	//input
	cout << "Enter num of rows: "; cin >> row_nums;
	cout << "Enter num of cols: "; cin >> col_nums;

	for (int r = 0; r < row_nums; r++)
	{
		for (int c = 0; c < col_nums; c++)
		{
			cin >> Arr2D[r][c];
		}
	}

	//process
	int remove_row;
	cout << "Enter the row you wanna remove: "; cin >> remove_row;

	//override the next row onto the previous row
	for (int r = remove_row-1; r < row_nums; r++)
	{
		for (int c = 0; c < col_nums; c++)
		{
			Arr2D[r][c] = Arr2D[r + 1][c];
		}
	}
	row_nums--;

	//output
	for (int r = 0; r < row_nums; r++)
	{
		for (int c = 0; c < col_nums; c++)
		{
			cout << Arr2D[r][c] << " ";
		}
		cout << endl;
	}
	return 0;
}