class Solution {
public:
	bool divisorGame(int N) {
		vector<bool> ans(N + 1, false);
		ans[1] = false;
		ans[2] = true;
		for (int i = 3; i <= N; i++)
		for (int j = 1; j<i; j++){
			if (i%j == 0 && ans[i - j] == false){
				ans[i] = true;
				break;
			}
		}
		return ans[N];
	}
};