#include<iostream>
using namespace std;

struct ListNode {
int val;
struct ListNode *next;
ListNode(int x) :
val(x), next(NULL) {
}
};

class Solution {
public:
	ListNode* deleteDuplication(ListNode* pHead)
	{
		if (pHead == nullptr || pHead->next == nullptr)
			return pHead;
		ListNode* Head = new ListNode(0);
		Head->next = pHead;
		ListNode* first = Head->next;
		ListNode* second = Head;
		while (first != nullptr){
			while (first->next != nullptr&&first->val != first->next->val){
				second = second->next;
				first = first->next;
			}
			while (first->next != nullptr&&first->val == first->next->val){
				first = first->next;
			}
			if (second->next != first){
				second->next = first->next;
			}
			first = first->next;
		}
		return Head->next;
	}
};