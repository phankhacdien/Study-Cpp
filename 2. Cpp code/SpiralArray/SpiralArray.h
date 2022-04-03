#pragma once
#include <iostream>
#include <vector>

using namespace std;

class SpiralArray
{
private:
	int maxR, maxC, top, bottom, obstacle_num;
	struct ObstacleInfo
	{
		int x;
		int y;
	};
	vector<ObstacleInfo> obstacle_info_;
	//vector<int> obstacle_info_y;
	int** spiral_arr;
public:
	void SetArraySize();
	void SetObstacle()
	{
		int end;
		int x;
		int y;

		cout << "How many obstacles you wanna set: "; cin >> obstacle_num;
		for (int i = 0; i < obstacle_num; i++)
		{
			cout << endl;
			cout << "Set x of obstacle number " << i << " : "; cin >> x;
			cout << "Set y of obstacle number " << i << " : "; cin >> y;
			obstacle_info_.push_back({ x, y });
			//obstacle_info_y.push_back(y);
		}
		cout << "==============================================" << endl;
	};
	//vector<vector<int>> CreatBlankSpiralArray();
	void CreatBlankSpiralArray();
	void AssignObstacleIntoArray();
	void ShowSpiralArray();
	void Spiral();
};