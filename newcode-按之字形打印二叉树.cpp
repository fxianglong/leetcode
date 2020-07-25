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
		stack<TreeNode*> st; //����Ҫ�����Ľڵ�
		queue<TreeNode*> q; //��Ϊ��ʱ���������и���
		st.push(pRoot);
		int dir = 1; //1. ��ջ˳���left��ʼ. 2.��ջ˳���right��ʼ.
		vector<int> v;
		while (!st.empty()){
			int size = st.size();
			for (int i = 0; i < size; i++){ //��ձ���stack�ṹ����������stack����������Ĺ���
					TreeNode *curr = st.top();
				st.pop();
				v.push_back(curr->val);
				TreeNode *first = (dir == 1) ? curr->left : curr->right;
				TreeNode *second = (dir == 1) ? curr->right : curr->left;
				//����һ�ַ���˳�����q��
				if (first != nullptr) q.push(first);
				if (second != nullptr) q.push(second);
			} // ���������Ҫ������нڵ㣬��result
				result.push_back(v);
			//����һ�ַ��ʽڵ���ջ����������
			while (!q.empty()){
				st.push(q.front());
				q.pop();
			} 
			// һ�������ϣ���Ҫ������ջ˳��
				dir = (dir == 1) ? 2 : 1;
			v.clear();
		} 
		return result;
	}


	vector<vector<int> > Print2(TreeNode* pRoot) {
		queue<TreeNode*> q;//����
		stack<TreeNode*> stk;//����
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