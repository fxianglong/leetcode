#include<iostream>
#include<vector>
using namespace std;
vector<int> mostVisited(int n, vector<int>& rounds) {
	vector<int> res;
	vector<int> ans(n+1, 0);
	for (int i = 0; i<rounds.size()-1; i++){
		int s = abs(rounds[i] - rounds[i + 1]);
		for (int j = 0; j<s; j++){
			ans[rounds[i + j]]++;
		}
	}
	int max = ans[0];
	res.push_back(0);
	for (int i = 1; i < ans.size(); i++){
		if (ans[i] == max){
			res.push_back(i);
		}
		else if (ans[i] > max)
		{
			res.clear();
			res.push_back(i);
		}
		else{
			continue;
		}
	}
	for (int i = 0; i < res.size();i++){
		cout << res[i];
		if (i != res.size() - 1){
			cout << " ";
		}
	}
	cout << endl;
	return res;
}

int main(){
	int n = 7;
//	cin >> n;
	vector<int> ans = { 1,3,5,7 };
	mostVisited(n, ans);
	system("pause");
	return 0;
}