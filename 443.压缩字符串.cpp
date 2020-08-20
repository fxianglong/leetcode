#include<iostream>
#include<string>
#include<vector>
using namespace std;
int compress(vector<char>& chars) {
	string s;
	for (int i = 0; i<chars.size(); i++){
		int count = 1;
		int j = i + 1;
		while (j<chars.size()&&chars[i] == chars[j]){
			count++;
			j++;
			i++;
		}
		if (count == 1)
			s += chars[i];
		else{
			s += chars[i];
			s += to_string(count);
		}
	}
	return s.size();
}
int main(){
	vector<char> ans;
	ans.push_back('z');
	ans.push_back('z'); 
	ans.push_back('a'); 
	ans.push_back('b');
	ans.push_back('b');
	ans.push_back('b');
	ans.push_back('b');
	ans.push_back('b');
	ans.push_back('b');
	ans.push_back('b');
	ans.push_back('b');
	ans.push_back('b'); 
	ans.push_back('b');
	ans.push_back('b');
	ans.push_back('b');
	ans.push_back('b');
	ans.push_back('b');
	cout << compress(ans) << endl;
	return 0;
}