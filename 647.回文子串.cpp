class Solution {
	int helper(string &s, int i, int j){
		while (j>i){
			if (s[i] != s[j])
				return false;
		}
		return true;
	}
public:
	int countSubstrings(string s) {
		// int count=0;
		// for(int i=0;i<s.size();i++){
		//     for(int j=s.size()-1;j>=i;j--){
		//         if(helper(s,i,j)){
		//             count++;
		//         }
		//     }
		// }
		// return count;
		int n = s.size(), ans = 0;
		for (int i = 0; i < 2 * n - 1; ++i) {
			int l = i / 2, r = i / 2 + i % 2;
			while (l >= 0 && r < n && s[l] == s[r]) {
				--l;
				++r;
				++ans;
			}
		}
		return ans;
	}
};