#include "BracketSearch.h"
#include <iostream>

using namespace std;

void BracketSearch::Excute()
{
	srand(time(NULL));
	int rand_num = rand() % 100 + 1;
	bool rs = false;
	int mode_choose;

	cout << "You wanna guess or computer guess [Computer Guess : 1 / User Guess : 2]: "; cin >> mode_choose;

	while (!rs)
	{
		switch (mode_choose)
		{
		case 1:
			LetUserGuess();
			gs_num++;
			rs = Evaluate(rand_num);
		case 2:
			ComputerGuess();
		}
	}
}

void BracketSearch::LetUserGuess()
{
	cout << "Guess onr number from 1 to 100: "; cin >> gs;
}

void BracketSearch::ComputerGuess()
{

}

bool BracketSearch::Evaluate(int &rand_num)
{
	if (gs > rand_num)
	{
		cout << "Too high." << endl;
		return false;
	}
	else if (gs < rand_num)
	{
		cout << "Too low." << endl;
		return false;
	}
	else
	{
		cout << "Right."<<endl;
		cout << "You have guessed " << gs_num << " times." << endl;
		return true;
	}
}