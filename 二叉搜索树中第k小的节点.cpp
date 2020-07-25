#include<iostream>
#include<vector>
using namespace std;
struct TreeNode {
int val;
struct TreeNode *left;
struct TreeNode *right;
TreeNode(int x) :
val(x), left(NULL), right(NULL) {
}
};

class Solution {
	void helper(TreeNode* root, vector<TreeNode*> &res){
		if (root == nullptr)
			return;
		helper(root->left, res);
		res.push_back(root);
		helper(root->right, res);
	}
public:
	TreeNode* KthNode(TreeNode* pRoot, int k)
	{
		vector<TreeNode*> res;
		if (pRoot == nullptr || k <= 0)
			return nullptr;
		helper(pRoot, res);
		if (k <= res.size())
			return res[k - 1];
		else
			return nullptr;
	}


};