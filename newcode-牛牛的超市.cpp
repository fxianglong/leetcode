#include<iostream>
using namespace std;
#include<vector>
/**
*
* @param n int���� ��ţ��ֵ������
* @param x int���� ��ţ��ӵ�е�Ǯ��
* @param a int����vector<vector<>> ���ڶ���vector�еĵ�һ�б�ʾ��ֵ���ڶ��б�ʾţţӵ�б�ֵ�ĸ���
* @return int����
*/
int solve(int n, int x, vector<vector<int> >& a) {
	vector<vector<int>> ans(n + 1, vector<int>(x + 1, 0));
	ans[0][0] = 1;
	for (int i = 1; i <= n; i++)
	for (int j = 0; j <= x; j++)
	for (int k = 0; k <= a[i - 1][1]; k++){
		if (ans[i - 1][j] > 0 && j + k*a[i - 1][0] <= x)
			ans[i][j + k*a[i - 1][0]] += ans[i - 1][j];
	}
	return ans[n][x];
}

int main(){
	vector<vector<int>> ans = { { 1, 5 }, { 2, 4 } };
	cout << solve(2,10,ans) << endl;
	system("pause");
	return 0;
}