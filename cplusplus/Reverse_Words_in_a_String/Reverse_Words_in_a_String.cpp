// Reverse_Words_in_a_String.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <stack>
#include <vector>
#include <iostream>

using namespace std;

class Solution 
{
public:
	void reverseWords(string &s)
	{
		if (s == "")
			return;

		string strTemp = s;
		stack<string> subStrings;
		size_t beginPos;
		size_t endPos;
		size_t subStrLength;

		do
		{
			beginPos = strTemp.find_first_not_of(' ');
			if (beginPos != string::npos)
			{
				strTemp = strTemp.substr(beginPos);
				beginPos = 0;
				endPos = strTemp.find_first_of(' ');
				if (endPos != string::npos)
				{
					subStrLength = endPos - beginPos;
					subStrings.push(strTemp.substr(beginPos, subStrLength));
					strTemp = strTemp.substr(endPos + 1);
				}
				else
				{
					subStrLength = strTemp.size() - beginPos;
					subStrings.push(strTemp.substr(beginPos, subStrLength));
					strTemp = strTemp.substr(strTemp.size());
				}
			}
			else
			{
				strTemp = "";
			}
		} while (!strTemp.empty());

		strTemp = "";
		while (!subStrings.empty())
		{
			string strTop = subStrings.top();
			strTemp.append(strTop);
			strTemp.append(" ");
			subStrings.pop();
		}

		if (strTemp != "")
		{
		    strTemp.pop_back();
		}

		s.swap(strTemp);
	}
protected:
private:
};

int _tmain(int argc, _TCHAR* argv[])
{
	Solution sol;
	string strTest = "the sky is blue";
	sol.reverseWords(strTest);
	cout << strTest << endl;

	strTest = "";
	sol.reverseWords(strTest);
	cout << strTest << endl;

	strTest = " ";
	sol.reverseWords(strTest);
	cout << strTest << endl;

	strTest = "  ";
	sol.reverseWords(strTest);
	cout << strTest << endl;

	strTest = " the sky    is  blue  ";
	sol.reverseWords(strTest);
	cout << strTest << endl;

	return 0;
}

