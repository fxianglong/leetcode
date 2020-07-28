#include<iostream>
#include<vector>
using namespace std;
class NumArray {
private:
	int* sum;
public:
	NumArray(vector<int>& nums) {
		//sum[i] Îª nums[0 : i-1]µÄºÍ
		sum = new int[nums.size() + 1];
		sum[0] = 0;
		for (int i = 1; i <= nums.size(); i++)
			sum[i] = sum[i - 1] + nums[i - 1];
	}
	~NumArray(){
		delete[] sum;
	}
	int sumRange(int i, int j) {
		return sum[j + 1] - sum[i];
	}
};

/**
* Your NumArray object will be instantiated and called as such:
* NumArray* obj = new NumArray(nums);
* int param_1 = obj->sumRange(i,j);
*/