#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> mostVisited(int n, vector<int>& rounds) {
	vector<int> ans;
	int start = rounds.front();
	while (start != rounds.back()) {
		ans.push_back(start);
		start++;
		start = (start > n) ? start % n : start;
	}
	ans.push_back(start);
	sort(ans.begin(), ans.end());
	return ans;
}


//int main(){
//	vector<int> ans = { 1, 3, 5, 7 ,1};
//	vector<int> res = mostVisited(7, ans);
//	for (auto e : res){
//		cout << e << endl;
//	}
//	system("pause");
//	return 0;
//}