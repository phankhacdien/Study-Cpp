#include <iostream>
#include <string.h>
#include <algorithm>
#include "ValidParentheses.h"

using namespace std;

bool Solution::isOpenBrackets(char c)
{
	char* f = find(begin(open_brac), end(open_brac), c);
	if (f != end(open_brac)) return true;
	else return false;
}

bool Solution::LoopCheck(string& s, int& fw_idx, int& bw_idx)
{
	if (bw_idx < 0) return true;
	else if (isOpenBrackets(s[bw_idx]))
	{
		close_brac = GetClosebracket(s[bw_idx]);
		if (close_brac != s[static_cast<int>(fw_idx + 1)]) return false;
		else
		{
			bw_idx -= 1;
			fw_idx += 1;
			return LoopCheck(s, fw_idx, bw_idx);
		}
	}
	else
	{
		bw_idx -= 1;
		close_brac = GetClosebracket(s[bw_idx]);
		if (close_brac != s[static_cast<int> (bw_idx + 1)]) return false;
		else
		{
			bw_idx -= 1;
			return LoopCheck(s, fw_idx, bw_idx);
		}
	}
}

bool Solution::InitCheck(string s)
{
	int open_cnt = 0, close_cnt = 0;
	for (int i = 0; i < s.length(); i++)
	{
		if (isOpenBrackets(s[i])) open_cnt++;
	}
	close_cnt = s.length() - open_cnt;

	if (s.length() % 2 != 0) return false;
	else if (close_cnt != open_cnt) return false;
	else return true;
}
	

bool Solution::isValid(string s)
{
	int bw_idx, fw_idx, m = 0;
	bool check = InitCheck(s);

	if (!check) return false;
	else
	{
		for (int i = 0; i < 3; i++)
		{
			bw_idx = s.rfind(open_brac[i]);
			if (bw_idx > m) m = bw_idx;
		}
		bw_idx = m;
		fw_idx = bw_idx + 1;

		close_brac = GetClosebracket(s[bw_idx]);
		if (close_brac != s[fw_idx]) return false;
		else
		{
			bw_idx -= 1;
			return LoopCheck(s, fw_idx, bw_idx);
		}
	}
}

int main()
{
	string s;
	cout << "Input some parentheses: "; cin >> s;

	Solution run;
	bool rs = run.isValid(s);
	cout << rs << endl;
	return 0;
}