/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(root==nullptr) return nullptr;
        queue<Node*> q1;
        q1.push(root);
        while(!q1.empty())
        {
            queue<Node*> q2;
            while(!q1.empty()){
                Node* cur=q1.front();
                q1.pop();
                if(cur->left)
                q2.push(cur->left);
                if(cur->right)
                q2.push(cur->right);
                if(!q1.empty())
                {
                    cur->next=q1.front();
                }
                else{
                    cur->next=nullptr;
                }
            }
            q1=q2;
        }
        return root;
    }
};