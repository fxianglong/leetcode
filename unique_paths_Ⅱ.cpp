#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
	/**
	*
	* @param obstacleGrid int整型vector<vector<>>
	* @return int整型
	*/
	int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
		int col = obstacleGrid.size();
		int row = obstacleGrid[0].size();
		vector<vector<int>> ans(col + 1, vector<int>(row + 1, 0));
		if (obstacleGrid[0][0] == 1 || obstacleGrid[col - 1][row - 1] == 1)
			return 0;
		for (int i = 0; i < col; ++i) {
			if (obstacleGrid[i][0]) {
				break;
			}
			else {
				ans[i][0] = 1;
			}
		}
		for (int i = 0; i < row; ++i) {
			if (obstacleGrid[0][i]) {
				break;
			}
			else {
				ans[0][i] = 1;
			}
		}
		for (int i = 1; i<col; i++)
		for (int j = 1; j<row; j++){
			if (obstacleGrid[i][j] == 1)
			{
				ans[i][j] = 0;
				continue;
			}
			ans[i][j] = ans[i - 1][j] + ans[i][j - 1];
		}
		return ans[col - 1][row - 1];
	}
};