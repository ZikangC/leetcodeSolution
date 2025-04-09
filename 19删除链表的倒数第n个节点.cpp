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
        ListNode* fast = head;
        ListNode* low = new ListNode();
        low->next = head;
        head = low;
        for(int i= 0; i < n; i++){
            fast = fast->next;
        }
        while(fast){
            fast = fast->next;
            low = low->next;
        }
        low->next = low->next->next;
        return head->next;
    }
};
