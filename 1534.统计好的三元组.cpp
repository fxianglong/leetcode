class Solution {
public:
    int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
        vector<int> tmp_left(arr.size(), 0);
        vector<int> tmp_right(arr.size(), 0);
        int ans = 0;
        for (int i = 1; i + 1 < arr.size(); ++i) {
            int left_cnt = 0;
            int right_cnt = 0;
            for (int left_idx = 0; left_idx < i; ++left_idx) {
                if (abs(arr[i] - arr[left_idx]) <= a) {
                    tmp_left[left_cnt++] = arr[left_idx];
                }
            }
            for (int right_idx = i + 1; right_idx < arr.size(); ++right_idx) {
                if (abs(arr[right_idx] - arr[i]) <= b) {
                    tmp_right[right_cnt++] = arr[right_idx];
                }
            }
            
            sort(tmp_left.begin(), tmp_left.begin() + left_cnt);
            for (int right_idx = 0; right_idx < right_cnt; ++right_idx) {
                ans += upper_bound(tmp_left.begin(), tmp_left.begin() + left_cnt, tmp_right[right_idx] + c) - lower_bound(tmp_left.begin(), tmp_left.begin() + left_cnt, tmp_right[right_idx] - c);
            }
        }
        return ans;
    }
};