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
	int flag = 1;
public:
	bool isBalanced(TreeNode* root) {
		if (root == nullptr) return true;
		int l = DNS(root->left);
		int r = DNS(root->right);
		if (abs(l - r)<2 && isBalanced(root->left) && isBalanced(root->right))
			return true;
		return false;
	}
	int DNS(TreeNode* root)
	{
		if (root == nullptr)return 0;
		int l = DNS(root->left);
		int r = DNS(root->right);
		return max(l, r) + 1;
	}
};