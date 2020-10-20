#include<iostream>
#include<stack>
#include<queue>
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};
void reorderList(ListNode* head) {
	if (head == nullptr) {
		return;
	}
	vector<ListNode *> vec;
	ListNode *node = head;
	while (node != nullptr) {
		vec.emplace_back(node);
		node = node->next;
	}
	int i = 0, j = vec.size() - 1;
	while (i < j) {
		vec[i]->next = vec[j];
		i++;
		if (i == j) {
			break;
		}
		vec[j]->next = vec[i];
		j--;
	}
	vec[i]->next = nullptr;
}

int main(){
	ListNode* head = new ListNode(1);
	ListNode* pre = head;
	head->next = new ListNode(2);
	head = head->next;
	head->next = new ListNode(3);
	head = head->next;
	head->next = new ListNode(4);
	reorderList(pre);
	return 0;
}