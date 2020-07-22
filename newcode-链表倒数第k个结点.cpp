#include"newcodetest_head.h"
struct ListNode {
int val;
struct ListNode *next;
ListNode(int x) :
val(x), next(NULL) {
}
};
class Solution {
public:
	ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
		if (pListHead == nullptr || k<0)
			return NULL;
		ListNode* front = pListHead;
		ListNode* rear = pListHead;
		while (k>0 && front){
			k--;
			front = front->next;
		}
		while (front != NULL){
			rear = rear->next;
			front = front->next;
		}
		return k>0 ? NULL : rear;
	}
};