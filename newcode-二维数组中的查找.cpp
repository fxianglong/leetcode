#include"newcodetest_head.h"

bool Find(int target, vector<vector<int> > array) {
	int col = 0;
	int row = array[0].size() - 1;
	while (col<array.size() && row >= 0){
		if (target>array[col][row]){
			col++;
		}
		else if (target<array[col][row]){
			row--;
		}
		else
			return true;
	}
	return false;
}