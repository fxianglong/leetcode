//#include<iostream>
//#include<vector>
//using namespace std;
//int main(){
//	int n;
//	cin >> n;
//	vector<int> ans(n, 0);
//	int sum = 0;
//	for (int i = 0; i < n; i++)
//	{
//		cin >> ans[i];
//		sum += ans[i];
//	}
//	if (sum%n)
//		return -1;
//	int avg = sum / n;
//	int count = 0;
//	for (auto it : ans){
//		if (it == avg)
//			continue;
//		else{
//			int x = abs(it - avg);
//			if (x % 2){
//				return -1;
//			}
//			else{
//				count += (x / 2);
//			}
//		}
//	}
//	count /= 2;
//	cout << count << endl;
//	return 0;
//}