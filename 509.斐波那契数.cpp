#include<iostream>
using namespace std;
#include<vector>
class Solution {
public:
	int fib(int N) {
		// if(N==1)
		//     return 1;
		// if(N==0)
		//     return 0;
		// return fib(N-1)+fib(N-2);
		if (N == 0)
			return 0;
		vector<int> ans(N + 1, 0);
		ans[0] = 0;
		ans[1] = 1;
		for (int i = 2; i<N + 1; i++)
			ans[i] = ans[i - 1] + ans[i - 2];
		return ans[N];
	}
};