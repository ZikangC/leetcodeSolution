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
    ListNode* merge(ListNode* list1, ListNode* list2){
        ListNode* head = new ListNode(0);
        ListNode* dummy = head;
        while(list1 && list2){
            if(list1->val <= list2->val){
                head->next = list1;
                head = head->next;
                list1 = list1->next;
            }else{
                head->next = list2;
                head = head->next;
                list2 = list2->next;
            }
        }
        head->next = list1?list1:list2;
        return dummy->next;
    }
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next){
            return head;
        }
        ListNode* fast = head->next;
        ListNode* slow = head;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        fast = slow->next;
        slow->next = nullptr;
        head = sortList(head);
        slow = sortList(fast);
        fast = merge(head,slow);
        return fast;
    }
};
