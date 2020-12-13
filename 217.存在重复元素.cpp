class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        // unordered_set<int> s;
        // for(auto e:nums)
        // {
        //     if(s.insert(e).second==false)
        //         return true;
        // }
        // return false;
        unordered_map<int,int> m;
        for(auto e:nums)
        {
            m[e]++;
            if(m[e]>1)
                return true;
        }
        return false;
    }
};