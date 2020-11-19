class Solution {
public:
    void moveZeroes(vector<int>& nums) {
      int i=0,j=0;
      while(i<nums.size()){
          while(i<nums.size()&&nums[i]!=0){
              nums[j++]=nums[i];
              i++;
          }
          while(i<nums.size()&&nums[i]==0){
              i++;
          }
      }
      for(;j<nums.size();j++){
          nums[j]=0;
      }
    }
};