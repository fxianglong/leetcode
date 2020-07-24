class Solution {
public:
	/**
	* 分组
	* @param n int整型
	* @param k int整型
	* @param a int整型vector
	* @return int整型
	*/
	int solve(int n, int k, vector<int>& a) {
		int l = 0, r = 0, m, cnt, t;
		for (int i = 0; i<n; i++)
			r += a[i];
		if (k == 1)
			return r;
		while (l + 1<r){
			m = (l + r) >> 1;
			cnt = t = 0;
			for (int i = 0; i<n; i++){
				t += a[i];
				if (t >= m){
					cnt++;
					t = 0;
				}
			}
			if (cnt >= k)
				l = m;
			else
				r = m;
		}
		return (l + r) >> 1;
	}
};