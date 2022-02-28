#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Sort
{
public:
	Sort()
	{
		GetNums();
	}

	void AscendingSort();
	void GetNums();
	void Show();
private:
	vector<int> nums;
	int qty;
};

void Sort::GetNums()
{
	int num;
	int qty;
	cout << "Enter quantity of numbers you wanna sort: "; cin >> qty;
	//nums.resize(qty);
	for (int i = 0; i < qty; i++)
	{
		cout << "Enter number " << i << " :"; cin >> num;
		nums.push_back(num);
	}
	cout << "---------------------------";
}

void Sort::AscendingSort()
{
	for (int i = 0; i < nums.size(); i++)
	{
		int min_idx = i;
		for (int j = i + 1; j < nums.size(); j++)
		{
			if (nums[min_idx] > nums[j]) min_idx = j;
		}
		int temp = nums[min_idx];
		nums[min_idx] = nums[i];
		nums[i] = temp;
	}
}

void Sort::Show()
{
	cout << "Show result: ";
	for (int i = 0; i < nums.size(); i++)
	{
		cout << nums[i] << " ";
	}
}

int main()
{
	Sort ob;
	ob.AscendingSort();
	ob.Show();
	return 0;
}