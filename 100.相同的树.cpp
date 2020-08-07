#include<iostream>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
	bool isSameTree(TreeNode* p, TreeNode* q) {
		if (!p && !q) return true;
		if (!p || !q) return false;
		return (p->val == q->val)
			&& (isSameTree(p->left, q->left)
			&& isSameTree(p->right, q->right));
		// stack<TreeNode*> s1;
		// TreeNode* ptemp;
		// TreeNode* qtemp;
		// s1.push(p);
		// s1.push(q);
		// while(!s1.empty())
		// {
		//     ptemp=s1.top();
		//     s1.pop();           
		//     qtemp=s1.top();
		//     s1.pop();
		//     if(!ptemp&&!qtemp)  continue;
		//     else if(!ptemp||!qtemp)return false;
		//     else if(ptemp->val != qtemp->val)return false;
		//     else{
		//         s1.push(ptemp->left);
		//         s1.push(qtemp->left);
		//         s1.push(ptemp->right);
		//         s1.push(qtemp->right);
		//     }
		// }
		// return true;
	}
};