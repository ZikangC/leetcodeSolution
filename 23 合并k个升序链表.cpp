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
    ListNode* mergetwo(ListNode* first,ListNode* second){
        if(!first && !second){
            return nullptr;
        }
        ListNode* ans = new ListNode(0);
        ListNode* res =ans;
        while(first && second){
            if(first->val<= second->val){
                ans->next = first; 
                first = first->next;
            }else{
                ans->next = second;
                second = second->next;
            }
            ans = ans->next;
        }
        if(!first){
            ans->next = second;
        }else{
            ans->next = first;
        }
        return res->next;

    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int len = lists.size();
        if(len == 0){
            return nullptr;
        }else if(len == 1){
            return lists[0];
        }
        ListNode* res = lists[0];
        for(int i = 1; i < len; i++){
            res = mergetwo(res,lists[i]);
        }
        return res;
    }
};
