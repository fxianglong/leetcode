#include<iostream>
#include<stack>
using namespace std;
class Solution {
public:
	void push(int value) {
		stk.push(value);
		if (minstk.empty() || minstk.top() >= value)
			minstk.push(value);
	}
	void pop() {
		if (stk.top() == minstk.top())
			minstk.pop();
		stk.pop();
	}
	int top() {
		return stk.top();
	}
	int min() {
		return minstk.top();
	}
private:
	stack<int> stk;
	stack<int> minstk;
};