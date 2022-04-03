#include <iostream>
#include <vector>
#include <algorithm>
#include "SpiralArray.h"

using namespace std;

void SpiralArray::SetArraySize()
{
	cout << "Enter the x size of array: "; cin >> maxC;
	cout << "Enter the y size of array: "; cin >> maxR;
	cout << "==============================================" << endl;
}

void SpiralArray::CreatBlankSpiralArray()
{
	spiral_arr = new int* [maxR];
	for (int r = 0; r < maxR; r++)
	{
		spiral_arr[r] = new int[maxC];
	}

	for (int r = 0; r < maxR; r++)
	{
		for (int c = 0; c < maxC; c++)
		{
			spiral_arr[r][c] = '-';
		}
	}
}

//vector<vector<int>> SpiralArray::CreatBlankSpiralArray()
//{
//	vector<vector<int>> spiral_arr_(maxR, vector<int>(maxC, '-'));
//	return spiral_arr_;
//}

void SpiralArray::AssignObstacleIntoArray()
{
	if (obstacle_num > 0)
	{
		for (auto it = begin(obstacle_info_); it != end(obstacle_info_); ++it)
		{
			spiral_arr[it->y][it->x] = 'x';
		}
	}
}

void SpiralArray::ShowSpiralArray()
{
	for (int r = 0; r < maxR; r++)
	{
		for (int c = 0; c < maxC; c++)
		{
			if ((spiral_arr[r][c] == 'x') || (spiral_arr[r][c] == '-')) printf("%c\t", spiral_arr[r][c]);
			else printf("%d\t", spiral_arr[r][c]);
		}
		cout << endl;
	}
}

void SpiralArray::Spiral()
{
	int cumsum = 0;
	int current_r = 0;
	int current_c = 0;
	int end_r = maxR;
	int end_c = maxC;

	while ((current_r < end_r) && (current_c < end_c))
	{
		for (int i = current_r; i < end_c; i++)
		{
			if (spiral_arr[current_r][i] != 'x')
			{
				spiral_arr[current_r][i] = cumsum;
				cumsum++;
			}
			else
			{
				end_c = i;
				break;
			}
		}
		current_r++;

		for (int i = current_r; i < end_r; i++)
		{
			if (spiral_arr[i][end_c - 1] != 'x')
			{
				spiral_arr[i][end_c - 1] = cumsum;
				cumsum++;
			}
			else 
			{
				end_r = i;
				break;
			}
		}
		end_c--;

		if (current_c < end_c)
		{
			for (int i = end_c - 1; i > current_c - 1; i--)
			{
				if (spiral_arr[end_r - 1][i] != 'x')
				{
					spiral_arr[end_r - 1][i] = cumsum;
					cumsum++;
				}
				else
				{
					current_c = i + 1;
					break;
				}
			}
			end_r--;
		}

		if (current_r < end_r)
		{
			for (int i = end_r - 1; i > current_r - 1; i--)
			{
				if (spiral_arr[i][current_c] != 'x')
				{
					spiral_arr[i][current_c] = cumsum;
					cumsum++;
				}
				else 
				{
					current_r = i + 1;
					break;
				}
			}
			current_c++;
		}
	}
}

int main()
{
	bool isLoob = true;
	char YN;
	while (isLoob)
	{
		SpiralArray test;
		test.SetArraySize();
		test.SetObstacle();
		//vector<vector<int>> spiral_arr_ = test.CreatBlankSpiralArray();
		test.CreatBlankSpiralArray();
		test.AssignObstacleIntoArray();
		test.Spiral();
		test.ShowSpiralArray();
		
		cout << "Do you want try another array: [Y/N]"; cin >> YN;
		if ((YN == 'N') || (YN == 'n'))
		{
			isLoob = false;
		}
	}
	return 0;
}