/*
// Definition for a Node.
class Node {
public:
int val;
vector<Node*> neighbors;

Node() {
val = 0;
neighbors = vector<Node*>();
}

Node(int _val) {
val = _val;
neighbors = vector<Node*>();
}

Node(int _val, vector<Node*> _neighbors) {
val = _val;
neighbors = _neighbors;
}
};
*/

class Solution {
public:
	unordered_map<Node*, Node*> visited;
	Node* cloneGraph(Node* node) {
		if (node == nullptr) {
			return node;
		}

		// ����ýڵ��Ѿ������ʹ��ˣ���ֱ�Ӵӹ�ϣ����ȡ����Ӧ�Ŀ�¡�ڵ㷵��
		if (visited.find(node) != visited.end()) {
			return visited[node];
		}

		// ��¡�ڵ㣬ע�⵽Ϊ��������ǲ����¡�����ھӵ��б�
		Node* cloneNode = new Node(node->val);
		// ��ϣ��洢
		visited[node] = cloneNode;

		// �����ýڵ���ھӲ����¿�¡�ڵ���ھ��б�
		for (auto& neighbor : node->neighbors) {
			cloneNode->neighbors.emplace_back(cloneGraph(neighbor));
		}
		return cloneNode;
	}
};