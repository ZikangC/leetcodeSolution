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
    bool hasCycle(ListNode *head) {
        if(!head || !head->next || !head->next->next){
            return false;
        }
        int nums = 20000;
        ListNode* fast = head;
        ListNode* slow = head;
        while(nums-- && fast && slow){
            if(!fast->next){
                return false;
            }
            fast = fast->next->next;
            slow = slow->next;
            if(fast == slow){
                return true;
            }
        }
        return false;
    }
};
