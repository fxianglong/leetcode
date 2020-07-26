class Solution {
	vector<vector<int>> ans;
	int dir[4][2] = { { 1, 0 }, { -1, 0 }, { 0, 1 }, { 0, -1 } };
	int help(vector<vector<int>>& matrix, int i, int j, int row, int col){
		if (ans[i][j] != 0)
			return ans[i][j];
		int t = 0;
		for (int m = 0; m<4; m++){
			int ni = i + dir[m][0];
			int nj = j + dir[m][1];
			if (ni >= 0 && ni<row&&nj >= 0 && nj<col&&matrix[i][j]<matrix[ni][nj])
				t = max(t, help(matrix, ni, nj, row, col));
		}
		ans[i][j] = 1 + t;
		return ans[i][j];
	}
public:
	int longestIncreasingPath(vector<vector<int>>& matrix) {
		if (!matrix.size() || !matrix[0].size())
			return 0;
		ans = vector<vector<int>>(matrix.size(), vector<int>(matrix[0].size(), 0));
		int res = 0;
		for (int i = 0; i<matrix.size(); i++)
		for (int j = 0; j<matrix[0].size(); j++){
			res = max(res, help(matrix, i, j, matrix.size(), matrix[0].size()));
		}
		return res;
	}
};