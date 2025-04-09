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
    ListNode* swapPairs(ListNode* head) {
        
        ListNode* pre = new ListNode();
        ListNode* begin = pre;
        ListNode* next = nullptr;
        while(head && head->next){
            next = head->next->next;
            head->next->next = head;
            pre->next = head->next;
            pre = head;
            head = next;
        }
        pre->next = head;
        return begin->next;

    }
};
