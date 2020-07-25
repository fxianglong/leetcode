#include<iostream>
#include<vector>
#include<map>
using namespace std;

class Solution {
public:
	int MoreThanHalfNum_Solution(vector<int> numbers) {
		int len = numbers.size();
		map<int, int> ans;
		for (int i = 0; i<len; i++){
			ans[numbers[i]]++;
			if (ans[numbers[i]]>(len / 2))
				return numbers[i];
		}
		return 0;
	}
};