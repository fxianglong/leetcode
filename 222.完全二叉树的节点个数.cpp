#include<iostream>
using namespace std;
#include<queue>
#include<vector>
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
//int countNodes(TreeNode* root) {
//	if (root == nullptr)
//		return 0;
//	int left = countNodes(root->left);
//	int right = countNodes(root->right);
//	return left + right + 1;
//}


// 统计树的深度
int countLevels(TreeNode* root) {
	int levels = 0;
	while (root) {
		root = root->left; levels += 1;
	}
	return levels;
}
int countNodes(TreeNode* root){
	// 2. 利用完全二叉树性质简化遍历次数
	if (root == nullptr) return 0;
	int left_levels = countLevels(root->left);
	int right_levels = countLevels(root->right);
	// 左子树深度等于右子树深度, 则左子树是满二叉树
	if (left_levels == right_levels){
		return countNodes(root->right) + (1 << left_levels);
	}
	else{
		return countNodes(root->left) + (1 << right_levels);
	}
}

int main(){
	TreeNode* head = new TreeNode(1);
	TreeNode* root = head;
	head->left = new TreeNode(2);
	head->right = new TreeNode(3);
	TreeNode* left = head->left;
	TreeNode* right = head->right;
	left->left = new TreeNode(4);
	left->right = new TreeNode(5);
	right->left = new TreeNode(6);
	cout << countNodes(root) << endl;
	system("pause");
	return 0;
}