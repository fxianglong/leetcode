class Solution {
public:
    int trap(vector<int>& height) {
        if(height.size()<2)
            return 0;
        int left=0,right=height.size()-1;
        int leftmax=height[left],rightmax=height[right];
        int res=0;
        while(left<right){
            if(leftmax<rightmax){
                res+=leftmax-height[left++];
                leftmax=max(height[left],leftmax);
            }
            else{
                res+=rightmax-height[right--];
                rightmax=max(height[right],rightmax);
            }
        }
        return res;
    }
};