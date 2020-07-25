#include<iostream>
#include<vector>
#include<stack>
using namespace std;


class Solution {
public:
	bool IsPopOrder(vector<int> pushV, vector<int> popV) {
		if (pushV.size() != popV.size())
			return false;
		int inindex = 0;
		int outindex = 0;
		std::stack<int> _stk;
		while (outindex<popV.size())
		{
			while (_stk.size() == 0 || _stk.top() != popV[outindex]){
				if (inindex<pushV.size())
					_stk.push(pushV[inindex++]);
				else
					return false;
			}
			_stk.pop();
			outindex++;
		}
		return true;
	}
};