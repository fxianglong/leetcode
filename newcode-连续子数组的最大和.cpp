#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
	int FindGreatestSumOfSubArray(vector<int> array) {
		if (array.size() == 0)
			return 0;
		int max_value = array[0];
		int len = array.size();
		vector<int> dp(len, INT_MIN);
		dp[0] = array[0];
		for (int i = 1; i<len; i++){
			dp[i] = max(array[i] + dp[i - 1], array[i]);
			if (dp[i]>max_value)max_value = dp[i];
		}
		return max_value;
	}
};