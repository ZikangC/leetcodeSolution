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
    pair<ListNode*, ListNode*> reversepart(ListNode* first, ListNode* end) {
        ListNode* prev = nullptr;
        ListNode* curr = first;
        ListNode* endNext = end->next; // 保存结束位置的下一个节点
        
        while(curr != endNext) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        
        return {end, first}; // 返回新的头和尾
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head || k == 1) return head;
        int T = k;
        ListNode* firstbegin = head;
        ListNode* firstend = head;
        ListNode* res = new ListNode();
        ListNode* resbegin = res;
        ListNode* begin;
        ListNode* nxt = new ListNode();
        begin = head;
        int num = 0;
        while(head){
            head = head->next;
            num++;
        }
        int loop = num/k;
        head = begin;
        nxt = begin;
        while(loop--){
            T = k-1;
            while(T--){
                head = head->next;
            }
            nxt = head->next;
            auto [firstbegin,firstend] = reversepart(begin,head);
            res->next = firstbegin;
            res = firstend;
            begin = nxt;
            head = nxt;
        }
        res->next = begin;
        return resbegin->next;
        
    }
};
