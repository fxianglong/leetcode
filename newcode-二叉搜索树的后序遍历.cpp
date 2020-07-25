#include<iostream>
#include<vector>
using namespace std;

class Solution {
private:
	bool helper(vector<int> seq, int start, int end){
		if (start>end){
			return true;
		}
		int root = seq[end];
		int i = 0;
		while (i<end&&seq[i]<root)
			i++;
		for (int j = i; j<end; j++){
			if (seq[j]<root)
				return false;
		}
		return helper(seq, start, i - 1) && helper(seq, i, end - 1);
	}
public:
	bool VerifySquenceOfBST(vector<int> sequence) {
		if (sequence.size() == 0)
			return false;
		bool res = false;
		res = helper(sequence, 0, sequence.size() - 1);
		return res;
	}
};