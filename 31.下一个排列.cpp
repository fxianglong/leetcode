class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if (nums.size() < 2) {
            return;
        }
        int i = nums.size() - 2;
        while (i >= 0) {
            if (nums[i] < nums[i+1]) {
                break;
            }
            --i;
        }
        reverse(nums.begin()+i+1, nums.end());
        if (i < 0) {
            return;
        }
        int start = i+1;
        int end = nums.size()-1;
        while (start <= end) {
            int mid = start + (end-start) / 2;
            if (nums[mid] <= nums[i]) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        swap(nums[i], nums[start]);
    }
};