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
    ListNode *detectCycle(ListNode *head) {
        if(!head){
            return NULL;
        }
        ListNode* slow = head;
        ListNode* fast = head;
        if(!slow->next || !fast->next->next){
            return NULL;
        }
        slow = head->next;
        fast = head->next->next;
        while(slow != fast){
            if(!slow->next || !fast->next ||!fast->next->next){
                return NULL;
            }
            slow = slow->next;
            fast = fast->next->next;
        }
        while(head!=slow){
            head = head->next;
            slow = slow->next;
        }
        return head;
    }
};
