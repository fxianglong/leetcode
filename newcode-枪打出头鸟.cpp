#include<iostream>
#include<vector>
using namespace std;
long long solve(int n, vector<int>& a) {
	long long res = 0;
	//for (int i = 0; i<n; i++){
	//	for (int j = i - 1; j >= 0; j--){
	//		if (a[j]>a[i])
	//		{
	//			res += j;
	//			break;
	//		}
	//	}
	//}
	stack<int> stk;
	for (int i = 0; i<n; i++){
		while (!stk.empty() && a[stk.top()] <= a[i]){
			stk.pop();
		}
		if (!stk.empty())
			res += stk.top() + 1;
		stk.push(i);
	}
	return res;
	return res;
}

int main(){
	vector<int> ans = {5,4,3,2,1};
	cout << solve(ans.size(),ans) << endl;
	system("pause");
	return 0;
}