#include<iostream>
using namespace std;
struct TreeNode {
int val;
struct TreeNode *left;
struct TreeNode *right;
TreeNode(int x) :
val(x), left(NULL), right(NULL) {
}
};
bool IsSame(TreeNode* begin, TreeNode* mbegin){
	if (mbegin == nullptr)
		return true;
	if (begin == nullptr)
		return false;
	if (begin->val != mbegin->val)
		return false;
	return IsSame(begin->left, mbegin->left) && IsSame(begin->right, mbegin->right);
}
class Solution {
public:
	bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
	{
		if (pRoot1 == nullptr || pRoot2 == nullptr)
			return false;
		bool result = false;
		if (pRoot1->val == pRoot2->val)
			result = IsSame(pRoot1, pRoot2);
		if (!result){
			result = HasSubtree(pRoot1->left, pRoot2);
		}
		if (!result){
			result = HasSubtree(pRoot1->right, pRoot2);
		}
		return result;
	}
};