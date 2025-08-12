/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head){
            return NULL;
        }
        unordered_map<Node*,Node*> newnode;
        newnode[NULL] = NULL;
        Node* prev = new Node(0); 
        Node* begin = head;
        Node* res = head;
        while(head){
            Node* tmp = new Node(head->val);
            prev->next = tmp;
            prev = tmp;
            newnode[head] = tmp;
            head = head->next;
        }
        head = begin;
        begin = newnode[head];
        res = begin;
        while(head){
            begin->random = newnode[head->random];
            head = head->next;
            begin = begin->next;
        }
        return res;
    }
};
