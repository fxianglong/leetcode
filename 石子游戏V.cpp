#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<stdint.h>
using namespace std;

class Solution {
public:
	int64_t dp[501][501]; // ���仯���飬���ڱ����ظ�����
	int64_t sum[501]; // ǰ׺��
	int64_t optl[501][501], optr[501][501];
	int pos[501][501];

	int stoneGameV(vector<int>& stoneValue) {
		memset(dp, -1, sizeof(dp));

		//����һ��ǰ׺��
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
					// �ڴ��ڵı�Ե��ͣ��̽
					// ����ȷ���� L, ���� R �����ӣ�newpos ����ۼ� n - L + 1 �Ρ�
					// ����ƽ�����Ӷ�Ϊ O(1)��
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
					if (curpos < i) { // pos ������
						dp[i][j] = optl[i + 1][j];
					}
					else if (sum[curpos] - sum[i - 1] == sum[j] - sum[curpos]) { // pos ���ڣ���ǰ�����
						dp[i][j] = max(dp[i][j], optl[i][curpos]); // ����ǰһ��
						dp[i][j] = max(dp[i][j], optr[curpos + 1][j]); // ���Ժ�һ��
					}
					else { // pos ���ڣ���ǰ�����
						dp[i][j] = max(dp[i][j], optl[i][curpos]); // ����ǰһ��
						if (curpos + 2 <= j) { // �жϺ�һ���Ƿ����
							dp[i][j] = max(dp[i][j], optr[curpos + 2][j]); // ���Ժ�һ��
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