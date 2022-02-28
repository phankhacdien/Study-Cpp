#include <iostream>

using namespace std;

class BracketSearch
{
private:
	int gs, gs_num = 0;
	enum GuessType {USERGUESS = 2, COMPUTERGUESS = 1};
	GuessType mode;
public:
	void Excute();
	void LetUserGuess();
	bool Evaluate(int &rand_num);
	void ComputerGuess();
};