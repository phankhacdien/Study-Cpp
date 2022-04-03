#include <iostream>
#include <string>
#include <stack>

using namespace std;

class Solution
{
public:
	int Precedence(char c);
	string InfixToPostFix(string s);
};

int Solution::Precedence(char c)
{
	if (c == '^') return 3;
	else if (c == '*' || c == '/') return 2;
	else if (c == '+' || c == '-') return 1;
	else return -1;
}

string Solution::InfixToPostFix(string s)
{
	stack<char> st;
	string result;

	for (int i = 0; i < s.length(); i++)
	{
		char c = s[i];

		if ((c >= '0' && c <= '9') || (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) result += c;
		else if (c == '(') st.push(c);
		else if (c == ')')
		{
			while (st.top() != '(')
			{
				result += st.top();
				st.pop();
			}
			st.pop(); // pop "("
		}
		else
		{
			while (!st.empty() && Precedence(c) <= Precedence(st.top()))
			{
				result += st.top();
				st.pop();
			}
			st.push(c);
		}
	}

	while (!st.empty()) {
		result += st.top();
		st.pop();
	}

	return result;
}

int main()
{
	string ob;
	cout << "Enter the expression you wanna convert from infix to postfix: "; cin >> ob;

	Solution Run;
	string rs = Run.InfixToPostFix(ob);


	return 0;
}