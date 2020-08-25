#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<stdint.h>
using namespace std;

class Solution {
public:
	int64_t dp[501][501]; // 记忆化数组，用于避免重复计算
	int64_t sum[501]; // 前缀和
	int64_t optl[501][501], optr[501][501];
	int pos[501][501];

	int stoneGameV(vector<int>& stoneValue) {
		memset(dp, -1, sizeof(dp));

		//出来一下前缀和
		sum[0] = 0;
		for (int i = 0; i < stoneValue.size(); i++) {
			sum[i + 1] = sum[i] + stoneValue[i];
		}

		int n = stoneValue.size();
		for (int i = 1; i <= n; i++) {
			for (int j = i; j <= n; j++) {
				if (i == j) {
					pos[i][j] = i - 1;
				}
				else {
					pos[i][j] = pos[i][j - 1];
					int &newpos = pos[i][j];
					// 在大于的边缘不停试探
					// 对于确定的 L, 随着 R 的增加，newpos 最多累加 n - L + 1 次。
					// 所以平均复杂度为 O(1)。
					while (newpos + 1 <= j && sum[newpos + 1] - sum[i - 1] <= sum[j] - sum[newpos + 1]) {
						newpos++;
					}
				}
			}
		}

		for (int i = n; i >= 1; i--) {
			for (int j = i; j <= n; j++) {
				if (i == j) {
					dp[i][j] = 0;
					optl[i][j] = optr[i][j] = sum[i] - sum[j - 1];
				}
				else {
					int curpos = pos[i][j];
					if (curpos < i) { // pos 不存在
						dp[i][j] = optl[i + 1][j];
					}
					else if (sum[curpos] - sum[i - 1] == sum[j] - sum[curpos]) { // pos 存在，且前后相等
						dp[i][j] = max(dp[i][j], optl[i][curpos]); // 尝试前一半
						dp[i][j] = max(dp[i][j], optr[curpos + 1][j]); // 尝试后一半
					}
					else { // pos 存在，且前后不相等
						dp[i][j] = max(dp[i][j], optl[i][curpos]); // 尝试前一半
						if (curpos + 2 <= j) { // 判断后一半是否存在
							dp[i][j] = max(dp[i][j], optr[curpos + 2][j]); // 尝试后一半
						}
					}
					optl[i][j] = max(dp[i][j] + sum[j] - sum[i - 1], optl[i][j - 1]);
					optr[i][j] = max(dp[i][j] + sum[j] - sum[i - 1], optr[i + 1][j]);
				}
				// cout << i << " " << j << " " << dp[i][j] << " " << pos[i][j] << endl;
			}
		}
		return dp[1][n];
	}
};

int main(){
	vector<int> ans;
	Solution::stoneGameV(ans);

	return 0;
}