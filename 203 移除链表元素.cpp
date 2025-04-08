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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* begin = new ListNode(0,head);
        ListNode* pre,cur;
        while(head){
            if(head->val != val){
                break;
            }
            head = head->next;
        }
        begin = head;
        if(!begin){
            return nullptr;
        }
        while(head->next){
            if(head->next->val == val){
                head->next = head->next->next;
            }else{
                head = head->next;
            }
        }
        return begin;
    }
};
