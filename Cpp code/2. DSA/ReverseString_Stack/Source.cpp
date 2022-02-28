#include <iostream>
#include <string>
#include <stack>

using namespace std;

class Reverse
{
public:
	Reverse(string str):
		str_(str)
	{
		StringReverse(str_);
	}

private:
	string str_;
	void StringReverse(string s);
};

void Reverse::StringReverse(string s)
{
	stack<char> st;
	string rs;

	for (int i = 0; i < s.length(); i++)
	{
		st.push(s[i]);
	}

	for (int i = 0; i < s.length(); i++)
	{
		rs += st.top();
		st.pop();
	}

	cout << rs;
}

int main()
{
	string exp;
	cout << "Enter string you wanna reverse: "; cin >> exp;
	Reverse str(exp);
	return 0;
}