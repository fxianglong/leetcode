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
    vector<int> ans;
    void flashBack(TreeNode* t1,TreeNode* t2){
        if(t1 == t2)
            return;
        TreeNode* p = t1;
        TreeNode* q = p->right;
        do{
            TreeNode *temp = q->right;
            q->right = p;
            p = q;
            q = temp;
        }while(p != t2);
    }

    void printNode(TreeNode* t1,TreeNode* t2){
        flashBack(t1,t2);
        TreeNode *node = t2;
        while(true){
            ans.emplace_back(node->val);
            if(node == t1)
                break;
            node = node->right;
        }
        flashBack(t2,t1);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        if(root == NULL){
            return ans;
        }
        TreeNode *tempNode = new TreeNode(-1);
        tempNode->left = root;
        TreeNode *node = tempNode;
        while(node){
            if(node->left == NULL){
                node = node->right;
            }else{
                TreeNode *pre = node->left;
                while(pre->right != NULL && pre->right != node){
                    pre = pre->right;
                }
                if(pre->right == NULL){
                    pre->right = node;
                    node = node->left;
                }else{
                    printNode(node->left,pre);
                    pre->right = NULL;
                    node = node->right;
                }
            }

        }
        return ans;
    }
};