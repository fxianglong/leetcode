#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
	bool repeatedSubstringPattern(string s) {
		for (int i = 1; i<s.size(); i++){
			string ans = s.substr(0, i);
			if (s.size() % i == 0){
				int count = s.size() / i;
				string str = "";
				while (count--){
					str += ans;
				}
				if (str == s)
					return true;
			}
		}
		return false;
	}
};