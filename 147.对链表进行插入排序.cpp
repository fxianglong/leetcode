#include<iostream>
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* insertionSortList(ListNode* head) {
	if (head == nullptr) {
		return head;
	}
	ListNode* dummyHead = new ListNode(0);
	dummyHead->next = head;
	ListNode* lastSorted = head;
	ListNode* curr = head->next;
	while (curr != nullptr) {
		if (lastSorted->val <= curr->val) {
			lastSorted = lastSorted->next;
		}
		else {
			ListNode *prev = dummyHead;
			while (prev->next->val <= curr->val) {
				prev = prev->next;
			}
			lastSorted->next = curr->next;
			curr->next = prev->next;
			prev->next = curr;
		}
		curr = lastSorted->next;
	}
	return dummyHead->next;
}

int main(){
	ListNode* start = nullptr;
	start= new ListNode(4);
	ListNode* head = start;
	start->next = new ListNode(2);
	start = start->next;
	start->next = new ListNode(1);
	start = start->next;
	start->next = new ListNode(3);
//	start = start->next;
	//start->next = new ListNode(0);
	//start = start->next;
	insertionSortList(head);
	system("pause");
	return 0;
}