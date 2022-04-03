#include <iostream>

using namespace std;

void SelctionSort(int *array, int N)
{
	for (int i = 0; i < N-1; i++) 
	{
		int min_idx = i;
		for (int j = i+1; j < N; j++)
		{
			if (array[min_idx] > array[j]) min_idx = j;
		}
		int temp = array[i];
		array[i] = array[min_idx];
		array[min_idx] = temp;
	}
}

int main()
{
	int arr[5] = {5,4,3,2,1};
	int N = 5;
	/*for (int i = 0; i < N; i++)
	{
		arr[i] = N - i;
	}*/
	cout << "Array before sort: ";
	for (int i = 0; i < N; i++)
	{
		cout << arr[i] <<" ";
	}
	SelctionSort(arr, N);
	cout << "Array after sort: ";
	for (int i = 0; i < N; i++)
	{
		cout << arr[i] << " ";
	}
	return 0;
}