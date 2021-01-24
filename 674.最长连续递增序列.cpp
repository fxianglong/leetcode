class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        if(nums.size()==0)
            return 0;
        int key=1;
        int res=key;
        for(int i=1;i<nums.size();i++){
            if(nums[i]>nums[i-1]){
                key++;
            }
            else{
                res=res>key?res:key;
                key=1;
            }
        }
        res=res>key?res:key;
        return res;
    }
};