#include"newcodetest_head.h"

class Solution {
public:
	int rectCover(int number) {
		vector<int> ans(number + 1, 0);
		ans[1] = 1;
		ans[2] = 2;
		if (number<3){
			return ans[number];
		}
		for (int i = 3; i <= number; i++){
			ans[i] = ans[i - 1] + ans[i - 2];
		}
		return ans[number];
	}
};