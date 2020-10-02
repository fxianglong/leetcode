class Solution {
public:
    int numJewelsInStones(string J, string S) {
        map<char,int> ans;
        for(int i=0;i<J.size();i++){
            ans[J[i]]++;
        }
        int count=0;
        for(int i=0;i<S.size();i++){
            if(ans[S[i]]!=0)
            count++;
        }
        return count;
    }
};