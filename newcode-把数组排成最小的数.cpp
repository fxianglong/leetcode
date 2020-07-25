#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
class Solution {
	static bool cmp(int x, int y){
		string sx = to_string(x);
		string sy = to_string(y);
		string a = sx;
		string b = sy;
		a += sy;
		b += sx;
		return a<b;
	}
public:
	string PrintMinNumber(vector<int> numbers) {
		sort(numbers.begin(), numbers.end(), cmp);
		string res = "";
		for (int i = 0; i<numbers.size(); i++){
			res += to_string(numbers[i]);
		}
		return res;
	}
};