#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
	int integerBreak(int n) {
		// if(n<4)
		//     return n-1;
		// int x=n/3;
		// int y=n%3;
		// if(y==0)
		//     return pow(3,x);
		// else if(y==1)
		//     return pow(3,x-1)*4;
		// else
		//     return pow(3,x)*2;
		vector<int> dp(59);
		if (n<4)
			return n - 1;
		else
		{

			dp[4] = 4;
			dp[5] = 6;
			dp[6] = 9;
			for (int i = 7; i <= n; i++){
				dp[i] = 3 * dp[i - 3];
			}
		}
		return dp[n];
	}
};