#pragma once
#include <iostream>
#include <string.h>
#include <map>

using namespace std;

class Solution
{
public:
	Solution();
	bool isValid(string s);
	char GetClosebracket(const char &);
private:
	bool isOpenBrackets(char c);
	bool InitCheck(string s);
	char close_brac;
	char open_brac[3] = { '(', '[', '{' };
	bool LoopCheck(string& s, int& fw_idx, int& bw_idx);
	map<char, char> parentheses;
};

Solution::Solution()
{
	parentheses['('] = ')';
	parentheses['['] = ']';
	parentheses['{'] = '}';
}

char Solution::GetClosebracket(const char &open_brac)
{
	return parentheses[open_brac];
}