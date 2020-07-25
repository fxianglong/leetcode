#include<iostream>
using namespace std;


class ListNode {
public:
	int val;
	struct ListNode *next;
	ListNode(int x) :
		val(x), next(NULL) {
	}
};

ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
{
	if (pHead1 == NULL)
		return pHead2;
	if (pHead2 == NULL)
		return pHead1;
	ListNode* newHead = NULL;
	ListNode* newTail = NULL;
	while (pHead1&&pHead2){
		ListNode* p;
		p = pHead1->val >= pHead2->val ? pHead1 : pHead2;
		if (p == pHead1){
			pHead1 = pHead1->next;
		}
		else{
			pHead2 = pHead2->next;
		}
		if (newHead == NULL){
			newHead = p;
			newTail = p;
		}
		else{
			newTail->next = p;
			newTail = p;
		}
	}
	if (pHead1 == NULL){
		newTail->next = pHead2;
	}
	else{
		newTail->next = pHead1;
	}
	return newHead;
}
