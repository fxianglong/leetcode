class Solution {
public:
	int largest1BorderedSquare(vector<vector<int>>& grid) {
		int col = grid.size();
		if (col == 0)return 0;
		int row = grid[0].size();
		vector<vector<vector<int>>> dp(col + 1, vector<vector<int>>(row + 1, vector(2, 0)));
		int max_len = 0;
		for (int i = 1; i <= col; i++)
		for (int j = 1; j <= row; j++){
			if (grid[i - 1][j - 1] == 1){
				dp[i][j][0] += dp[i][j - 1][0] + 1;
				dp[i][j][1] += dp[i - 1][j][1] + 1;
				int len = min(dp[i][j][0], dp[i][j][1]);
				while (len){
					if (dp[i][j - len + 1][1] >= len&&dp[i - len + 1][j][0] >= len)
						break;
					len--;
				}
				max_len = max(max_len, len);
			}
		}
		return max_len*max_len;
	}
};