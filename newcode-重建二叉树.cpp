#include"newcodetest_head.h"
struct TreeNode {
    int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
	TreeNode* ConstructBinaryTree(vector<int> pre, int prestart, int preend,
	vector<int> vin, int vinstart, int vinend){
		if (prestart>preend || vinstart>vinend){
			return nullptr;
		}
		TreeNode* root = new TreeNode(pre[prestart]);
		for (int i = vinstart; i <= vinend; i++){
			if (vin[i] == pre[prestart])
			{
				root->left = ConstructBinaryTree(pre, prestart + 1, i + prestart - vinstart,
					vin, vinstart, i - 1);
				root->right = ConstructBinaryTree(pre, i + prestart - vinstart + 1, preend,
					vin, i + 1, vinend);
				break;
			}
		}
		return root;
	}
public:
	TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin) {
		if (pre.empty() || vin.empty())
			return nullptr;
		return ConstructBinaryTree(pre, 0, pre.size() - 1, vin, 0, vin.size() - 1);
	}
};