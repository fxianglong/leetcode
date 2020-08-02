//
//struct TreeNode {
//    int val;
//    TreeNode *left;
//    TreeNode *right;
//    TreeNode() : val(0), left(nullptr), right(nullptr) {}
//    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
//};
//
//class Solution {
//public:
//	void flatten(TreeNode* root) {
//		// while(root!=nullptr)
//		// {
//		//     if(root->left!=nullptr)
//		//     {
//		//         auto most_right=root->left;
//		//         while(most_right->right!=nullptr)most_right=most_right->right;
//		//         most_right->right=root->right;
//		//         root->right=root->left;
//		//         root->left=nullptr;
//		//     }
//		//     root=root->right;
//		// }
//		// return;
//
//
//		if (root == nullptr)return;
//		flatten(root->left);
//		flatten(root->right);
//		if (root->left != nullptr) {
//			auto pre = root->left;
//			while (pre->right != nullptr) pre = pre->right;
//			pre->right = root->right;
//			root->right = root->left;
//			root->left = nullptr;
//		}
//		root = root->right;
//		return;
//	}
//};