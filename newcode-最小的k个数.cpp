#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<functional>
using namespace std;

class Solution {
public:
	vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
		vector<int> res;
		if (k <= 0 || k>input.size() || input.size() == 0)
			return res;
		priority_queue<int, vector<int>, greater<int>> q;
		for (int i = 0; i<input.size(); i++){
			q.push(input[i]);
		}
		for (int i = 0; i<k; i++)
		{
			res.push_back(q.top());
			q.pop();
		}
		return res;
	}
};