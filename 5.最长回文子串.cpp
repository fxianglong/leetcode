#include<iostream>
#include<vector>
#include<string>
using namespace std;
//string longestPalindrome(string s) {
//	string res = "";
//	for (int i = 1; i<=s.size(); i++)
//	for (int j = i-1; j >= 0; j--){
//		string s1;
//		s1 = s.substr(j, i - j);
//		string ans = s1;
//		reverse(ans.begin(), ans.end());
//		if (ans == s1 && (s1.size()>res.size()))
//			res = s1;
//	}
//	return res;
//}

string longestPalindrome(string s) {
	int n = s.size();
	string res = "";
	vector<vector<int>> ans(n, vector<int>(n, 0));
	for (int l = 0; l<n; l++)
	for (int i = 0; i<n - l; i++)
	{
		int j;
		j = i + l;
		if (l == 0)
			ans[i][j] = 1;
		else if (l == 1)
			ans[i][j] = (s[i] == s[j]);
		else
			ans[i][j] = (s[i] == s[j] && ans[i + 1][j - 1]);
		if (ans[i][j] && ((l + 1)>res.size()))
			res = s.substr(i, l + 1);
	}
	return res;
}
int main(){
	string a ;
	cin >> a;
	cout << longestPalindrome(a) << endl;
	system("pause");
	return 0;
}