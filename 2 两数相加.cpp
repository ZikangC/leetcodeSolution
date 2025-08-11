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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* begin = new ListNode(0);
        ListNode* res = begin;
        int flag = 0;
        int sum = 0;
        while(l1 && l2){
            sum = l1->val + l2->val + flag;
            begin->next = new ListNode(sum%10);
            begin = begin->next;
            if(sum >= 10){
                flag = 1;
            }else{
                flag = 0;
            }
            l1 = l1->next;
            l2 = l2->next;
        }
        if(!l1){
            while(l2){
                sum = l2->val+flag;
                begin->next = new ListNode(sum%10);
                begin = begin->next;
                if(sum >= 10){
                    flag = 1;
                }else{
                    flag = 0;
                }
                l2 = l2->next;
            }
        }
        if(!l2){
            while(l1){
                sum = l1->val+flag;
                begin->next = new ListNode(sum%10);
                begin = begin->next;
                if(sum >= 10){
                    flag = 1;
                }else{
                    flag = 0;
                }
                l1 = l1->next;
            }
        }
        if(flag == 1){
            begin->next = new ListNode(1);
        }
        return res->next;
    }
};
