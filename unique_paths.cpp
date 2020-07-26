#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
	/**
	*
	* @param m int整型
	* @param n int整型
	* @return int整型
	*/
	int uniquePaths(int m, int n) {
		vector<vector<int>> ans(m, vector<int>(n, 0));
		for (int i = 0; i<m; i++)
		for (int j = 0; j<n; j++){
			if (i == 0 || j == 0)
			{
				ans[i][j] = 1;
				continue;
			}
			ans[i][j] = ans[i - 1][j] + ans[i][j - 1];
		}
		return ans[m - 1][n - 1];
	}
};


