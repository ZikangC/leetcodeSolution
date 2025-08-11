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
    ListNode* reverse(ListNode* head){
        ListNode* prev = nullptr;
        ListNode* cur = head;
        while(cur){
            ListNode* nxt = cur->next;
            cur->next = prev;
            prev = cur;
            cur = nxt;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        if(!head->next){
            return head;
        }
        ListNode* cnt = head;
        int nums = 0;
        while(cnt){
            nums++;
            cnt = cnt->next;
        }
        cnt = head;
        nums = nums/2;
        while(nums--){
            cnt = cnt->next;
        }
        ListNode* second = reverse(cnt);
        while(second){
            if(second->val != head->val){
                return false;
            }else{
                second = second->next;
                head = head->next;
            }
        }
        return true;
    }
};
