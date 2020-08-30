class Solution {
	void Reverse(string& s, int left, int right){
		while (left<right){
			swap(s[left], s[right]);
			left++; right--;
		}
	}
public:
	string reverseWords(string s) {
		int left = 0;
		for (int i = 0; i<s.size(); i++){
			if (s[i + 1] == ' ' || i == s.size() - 1){
				Reverse(s, left, i);
				i++;
				left = i + 1;
			}
		}
		return s;
	}
};