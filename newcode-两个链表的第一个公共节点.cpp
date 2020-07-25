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
	ListNode* GetLength(ListNode* p, int &len){
		if (p == nullptr)
			return p;
		ListNode* end;
		while (p){
			end = p;
			p = p->next;
			len++;
		}
		return end;
	}
public:
	ListNode* FindFirstCommonNode(ListNode* pHead1, ListNode* pHead2) {
		if (pHead1 == nullptr || pHead2 == nullptr)
			return nullptr;
		int len1 = 0, len2 = 0;
		ListNode* end1 = GetLength(pHead1, len1);
		ListNode* end2 = GetLength(pHead2, len2);
		if (end1 != end2)
			return nullptr;
		int step = len1>len2 ? len1 - len2 : len2 - len1;
		if (len1>len2){
			while (step){
				pHead1 = pHead1->next;
				step--;
			}
		}
		else{
			while (step){
				pHead2 = pHead2->next;
				step--;
			}
		}
		while (pHead1&&pHead2){
			if (pHead1 == pHead2)
				return pHead1;
			else{
				pHead1 = pHead1->next;
				pHead2 = pHead2->next;
			}
		}
		return nullptr;
	}
};