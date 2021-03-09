class Solution {
public:
    string removeDuplicates(string S) {
        stack<char> stk;
        for(int i=0;i<S.size();i++){
            if(stk.empty()||stk.top()!=S[i]){
                stk.push(S[i]);
            }
            else if(stk.top()==S[i]){
                stk.pop();
            }
        }
        string s;
        while(!stk.empty()){
            s+=stk.top();
            stk.pop();
        }
        reverse(s.begin(),s.end());
        return s;
    }
};