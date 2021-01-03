/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        // ListNode* small = new ListNode(0);
        // ListNode* smallHead = small;
        // ListNode* large = new ListNode(0);
        // ListNode* largeHead = large;
        // while (head != nullptr) {
        //     if (head->val < x) {
        //         small->next = head;
        //         small = small->next;
        //     } else {
        //         large->next = head;
        //         large = large->next;
        //     }
        //     head = head->next;
        // }
        // large->next = nullptr;
        // small->next = largeHead->next;
        // return smallHead->next;

        ListNode* h = new ListNode(-1), *h1 = h;
        vector<int> large, small;
        while(head){
            if(head->val < x) small.push_back(head->val);
            else large.push_back(head->val);
            head = head->next;
        }
        for(int i : small){
            h1->next = new ListNode(i); h1 = h1->next;
        }
        for(int i : large){
            h1->next = new ListNode(i); h1 = h1->next;           
        }
        return h->next;
    }
};