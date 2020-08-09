//#include<iostream>
//#include<vector>
//#include<cmath>
//using namespace std;
//
//bool dfs(int a, int b, vector<vector<int> > & mat, vector<int>& visit)
//{
//	if (mat[a][b] == 1)
//		return true;
//	visit[a] = 1; //记录已访问过的节点
//	for (int i = 0; i < mat.size(); i++)
//	{
//		if (i != a && visit[i] == 0 && mat[a][i] == 1)
//		{
//			if (dfs(i, b, mat, visit))
//				return true;
//
//		}
//	}
//	return false;
//}
//void solver(vector<vector<int> > & egde, int n, int m)
//{
//	vector<vector<int> > mat(n, vector<int>(n, 0));
//	for (int i = 0; i< m; i++)
//	{
//		int x = egde[i][0] - 1;
//		int y = egde[i][1] - 1;
//		mat[x][y] = 1;
//	}
//	int ans = 0;
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = i + 1; j < n; j++)
//		{
//			vector<int> visit1(n, 0);
//			vector<int> visit2(n, 0);
//			if (dfs(i, j, mat, visit1) && dfs(j, i, mat, visit2))
//				ans += 1;
//		}
//	}
//	cout << ans << endl;
//	return;
//
//}
//
//int main()
//{
//
//	int n, m;
//	cin >> n >> m;
//	vector<vector<int> >  egde(m, vector<int>(2));
//	for (int i = 0; i< m; i++)
//	{
//		for (int j = 0; j<2; j++)
//			cin >> egde[i][j];
//	}
//	solver(egde, n, m);
//
//	return 0;
//}