#include<iostream>
using namespace std;
#include<vector>
int a[10000], n;
int res;

void dfs(int i, int s1, int s2, int delet) {
	if (i == n)   //当第一轮分完，进行判断
	{
		if (s1 == s2 && delet < res) {   //若两个人的价值相等，判断丢弃值是否最小，是则更新
			res = delet;
		}
		return;   //结束本轮判断
	}

	dfs(i + 1, s1 + a[i], s2, delet);  //把a[i]分给第一个人
	dfs(i + 1, s1, s2 + a[i], delet);  //把a[i]分给第二个人
	dfs(i + 1, s1, s2, delet + a[i]);  //丢弃
}

int main()
{
	int t;
	cin >> t;
	while (t--) {
		cin >> n;
		res = 0;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			res += a[i];
		}
		dfs(0, 0, 0, 0);
		cout << res << endl;
	}
	system("pause");
	return 0;
}




//#include<iostream>
//#include<vector>
//#include<cmath>
//#include<algorithm>
//
//using namespace std;
//void push(int i, vector<int>& bucket, vector<int> & V, int& res, int& sum)
//{
//	if (bucket[0] == bucket[1])
//		res = min(res, sum - bucket[0] * 2);
//	if (i < 0)
//		return;//bucket[0] == bucket[1];
//	for (int j = 0; j < 2; j++)
//	{
//		if (bucket[j] + V  [i] > ceil(sum / 2)) //放入第j个桶前判断是否大于sum/2,大于则剪枝
//			continue;
//		bucket[j] += V[i]; //放第j个桶
//		push(i - 1, bucket, V, res, sum);
//		bucket[j] -= V[i]; // 回溯
//	}
//}
//
//void solver(vector<int>& V, int n)
//{
//	if (n == 1)
//	{
//		cout << V[0] << endl;
//		return;
//	}
//	sort(V.begin(), V.end()); //从小到大排序
//	vector<int> bucket(2, 0); //  初始化两个桶
//	int sum = 0;
//	for (int i = 0; i < n; i++) //对数组求和
//		sum += V[i];
//	int res = sum; //丢弃的物品价值
//	for (int i = n - 1; i >= 0; i--)
//	{
//		push(i, bucket, V, res, sum);
//	}
//
//	cout << res << endl;
//}
//
//int main()
//{
//
//	int T;
//	cin >> T;
//	for (int i = 0; i< T; i++)
//	{
//		int n;
//		cin >> n;
//		vector<int> V(n);
//		for (int j = 0; j< n; j++)
//			cin >> V[j];
//		solver(V, n);
//	}
//	return 0;
//}