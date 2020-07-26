#include<iostream>
#include<unordered_set>
#include<vector>
#include<string>
using namespace std;
class Solution {
public:
	bool wordBreak(string s, unordered_set<string> &dict) {
		if (s.empty() || dict.empty())
			return false;
		int max_length = 0;
		for (auto it = dict.begin(); it != dict.end(); it++){
			if (max_length < it->size()){
				max_length = it->size();
			}
		}
		vector<bool> ans(s.size() + 1, false);
		ans[0] = true;
		for (int i = 1; i <= s.size(); i++){
			for (int j = i - 1; j >= 0; j--){
				if ((i - j)>max_length)
				{
					break;
				}
				if (ans[j] == true && dict.find(s.substr(j, i - j)) != dict.end())
				{
					ans[i] = true;
					break;
				}
			}
		}
		return ans[s.size()];
	}
};