#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int minimumTotal(vector<vector<int> > &triangle) {
	int col = triangle.size();
	int row = triangle[col - 1].size();
	vector<int> dp(row, 100005);
	dp[0] = 0;
	for (int i = 0; i<col; i++)
	for (int j = triangle[i].size() - 1;j>=0; j--){
		if (j == 0){
			dp[j] += triangle[i][j];
			continue;
		}
		dp[j] = min(dp[j] + triangle[i][j], dp[j - 1] + triangle[i][j]);
	}
	int Min = INT_MAX;
	for (int i = 0; i<dp.size(); i++)
		Min = min(Min, dp[i]);
	return Min;
}

int main(){
	vector<vector<int>> triangle = { { -1 },{-2,-3} };
	cout << minimumTotal(triangle) << endl;
	system("pause");
	return 0;
}