class Solution {
public:
	/**
	* ����
	* @param n int����
	* @param k int����
	* @param a int����vector
	* @return int����
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