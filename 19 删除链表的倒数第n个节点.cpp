/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head->next == nullptr){
            return nullptr;
        }
        ListNode* begin = head;
        ListNode* pre = new ListNode();
        ListNode* res = pre;
        pre->next = head;
        ListNode* fast = head;
        while(n > 0){
            fast = fast->next;
            n--;
        }
        while(fast){
            fast = fast->next;
            begin = begin->next;
            pre = pre->next;
        }
        pre->next = begin->next;
        return res->next;
    }
};
