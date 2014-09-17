// Evaluate_Reverse_Polish_Notation.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <string>
#include <stack>
#include <iostream>

using namespace std;

class Solution
{
public:
	int evalRPN(vector<string> &tokens) {
		if (tokens.size() < 3 && tokens.size() != 1)
			return 0;
		if (tokens.size() == 1)
			return stoi(tokens[0]);
		string strOperator = "*/+-";
		stack<int> s;
		int iResult = 0;
		for (vector<string>::iterator itr = tokens.begin(); itr != tokens.end(); ++itr)
		{
			if (strOperator.find(*itr) == string::npos)
			{
				int iElement = stoi(*itr);
				s.push(iElement);
			}
			else
			{
				if (!s.empty())
				{
					int iNumberA = s.top();;
					s.pop();
					int iNumberB = s.top();
					if (*itr == "+")
					{
						iResult = iNumberB + iNumberA;
					}
					else if (*itr == "-")
					{
						iResult = iNumberB - iNumberA;
					}
					else if (*itr == "*")
					{
						iResult = iNumberB * iNumberA;
					}
					else
					{
						iResult = iNumberB / iNumberA;
					}
					s.pop();
					s.push(iResult);
				}
			}
		}
		return iResult;
	}
protected:
private:
};

int _tmain(int argc, _TCHAR* argv[])
{
	Solution sol;

	vector<string> vTest = { "2", "1", "+", "3", "*" };
	int iResult = sol.evalRPN(vTest);
	cout << iResult << endl;

	vTest = { "4", "13", "5", "/", "+" };
	iResult = sol.evalRPN(vTest);
	cout << iResult << endl;

	return 0;
}

