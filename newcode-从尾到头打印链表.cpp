#include"newcodetest_head.h"

struct ListNode {
      int val;
	  struct ListNode *next;
	  ListNode(int x) :
	  val(x), next(NULL) {}
};
//方法1
class Solution {
public:
	vector<int> printListFromTailToHead(ListNode* head) {
		vector<int> res;
		while (head != NULL){
			res.push_back(head->val);
			head = head->next;
		}
		reverse(res.begin(), res.end());
		return res;
	}
};

//方法2
class Solution1 {
public:
	vector<int> ans;
	vector<int> printListFromTailToHead(ListNode* head) {
		if (head == NULL)
			return ans;
		printListFromTailToHead(head->next);
		ans.push_back(head->val);
		return ans;
	}
};