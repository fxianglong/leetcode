#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
	vector<vector<int> > FindContinuousSequence(int sum) {
		vector<vector<int>> res;
		int low = 1;
		int high = 2;
		while (low<high){
			int total = (low + high)*(high - low + 1) / 2;
			if (sum == total){
				vector<int> ans;
				for (int i = low; i <= high; i++)
					ans.push_back(i);
				res.push_back(ans);
			}
			if (total<sum)
				high++;
			else
				low++;
		}
		return res;
	}
};