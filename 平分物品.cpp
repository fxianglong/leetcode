#include<iostream>
using namespace std;
#include<vector>
int a[10000], n;
int res;

void dfs(int i, int s1, int s2, int delet) {
	if (i == n)   //����һ�ַ��꣬�����ж�
	{
		if (s1 == s2 && delet < res) {   //�������˵ļ�ֵ��ȣ��ж϶���ֵ�Ƿ���С���������
			res = delet;
		}
		return;   //���������ж�
	}

	dfs(i + 1, s1 + a[i], s2, delet);  //��a[i]�ָ���һ����
	dfs(i + 1, s1, s2 + a[i], delet);  //��a[i]�ָ��ڶ�����
	dfs(i + 1, s1, s2, delet + a[i]);  //����
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
//		if (bucket[j] + V  [i] > ceil(sum / 2)) //�����j��Ͱǰ�ж��Ƿ����sum/2,�������֦
//			continue;
//		bucket[j] += V[i]; //�ŵ�j��Ͱ
//		push(i - 1, bucket, V, res, sum);
//		bucket[j] -= V[i]; // ����
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
//	sort(V.begin(), V.end()); //��С��������
//	vector<int> bucket(2, 0); //  ��ʼ������Ͱ
//	int sum = 0;
//	for (int i = 0; i < n; i++) //���������
//		sum += V[i];
//	int res = sum; //��������Ʒ��ֵ
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