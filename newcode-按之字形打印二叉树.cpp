#include<iostream>
#include<queue>
#include<stack>
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
public:
	vector<vector<int> > Print(TreeNode* pRoot) {
		vector<vector<int> > result;
		if (pRoot == nullptr){
			return result;
		} 
		stack<TreeNode*> st; //保存要遍历的节点
		queue<TreeNode*> q; //作为临时队列来进行辅助
		st.push(pRoot);
		int dir = 1; //1. 入栈顺序从left开始. 2.入栈顺序从right开始.
		vector<int> v;
		while (!st.empty()){
			int size = st.size();
			for (int i = 0; i < size; i++){ //清空本轮stack结构，并遍历，stack本身有逆序的功能
					TreeNode *curr = st.top();
				st.pop();
				v.push_back(curr->val);
				TreeNode *first = (dir == 1) ? curr->left : curr->right;
				TreeNode *second = (dir == 1) ? curr->right : curr->left;
				//将下一轮访问顺序放入q中
				if (first != nullptr) q.push(first);
				if (second != nullptr) q.push(second);
			} // 将本层符合要求的所有节点，入result
				result.push_back(v);
			//将下一轮访问节点入栈，进行逆序
			while (!q.empty()){
				st.push(q.front());
				q.pop();
			} 
			// 一层遍历完毕，就要更改入栈顺序
				dir = (dir == 1) ? 2 : 1;
			v.clear();
		} 
		return result;
	}


	vector<vector<int> > Print2(TreeNode* pRoot) {
		queue<TreeNode*> q;//左右
		stack<TreeNode*> stk;//右左
		vector<vector<int>> res;
		q.push(pRoot);
		while (!q.empty() || stk.empty()){
			vector<int> list;
			while (!q.empty()){
				list.push_back(q.front()->val);
				if (q.front()->left)
					stk.push(q.front()->left);
				if (q.front()->right)
					stk.push(q.front()->right);
				q.pop();
			}
			if (q.empty()){
				res.push_back(list);
				list.clear();
			}
			while (!stk.empty()){
				list.push_back(stk.top()->val);
				if (stk.top()->left)
					q.push(stk.top()->left);
				if (stk.top()->right)
					q.push(stk.top()->right);
				stk.pop();
			}
			if (stk.empty()){
				res.push_back(list);
				list.clear();
			}
		}
		return res;
	}
};