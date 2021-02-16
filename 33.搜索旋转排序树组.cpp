class Solution {public:    int search(vector<int>& nums, int target) {        // int res=-1;        // for(int i=0;i<nums.size();i++){        //     if(nums[i]==target){        //         res=i;        //         break;        //     }        // }        // return res;        int l = 0, r = nums.size();        while(l < r) {            int mid = l + ((r - l) >> 1);            if(nums[mid] == target)                return mid;            else if(nums[mid] > nums[l]) { // 判断l和mid的位置是否处在同一个有序序列中                // target没有位于nums[l]和nums[mid]之间，即位于后面的有序序列，这时有两种情况，用或                if((nums[l] > target && nums[mid] > target) || nums[mid] < target)                     l = mid + 1;                else                    r = mid;            }            else { // l和mid的不在同一个有序序列中                    if(nums[l] > target && nums[mid] < target) // target位于后面的有序序列中                        l = mid + 1;                    else                        r = mid;            }        }        return -1;    }};