/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
    //     vector<int> res;
    //     ProTraversal(root,res);
    //     return res;
    // }
    // void ProTraversal(TreeNode* root,vector<int>& ans)
    // {
        // if(root==NULL) return ;
        // ans.emplace_back(root->val);
        // ProTraversal(root->left,ans);
        // ProTraversal(root->right,ans);



        stack<TreeNode*> _stk;
        vector<int> ans;
        TreeNode* temp=root;
        while(temp!=NULL||!_stk.empty()){
            while(temp!=NULL){
                ans.push_back(temp->val);
                _stk.push(temp);
                temp=temp->left;
            }
            temp=_stk.top();
            _stk.pop();
            temp=temp->right;
        }
        return ans;
    }
};