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
	void helper(TreeNode* root, int ex, vector<vector<int>>& res, vector<int>& list){
		if (root == nullptr)
			return;
		ex -= root->val;
		list.push_back(root->val);
		if (root->left == nullptr&&root->right == nullptr&&ex == 0){
			res.push_back(list);
		}
		helper(root->left, ex, res, list);
		helper(root->right, ex, res, list);
		list.pop_back();
	}
public:
	vector<vector<int> > FindPath(TreeNode* root, int expectNumber) {
		vector<vector<int>> res;
		vector<int> list;
		helper(root, expectNumber, res, list);
		return res;
	}
};