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
    unordered_map<Node*,Node*> map;

    Node* copyRandomList(Node* head) {
        if(head == nullptr) return nullptr;
        if(map.count(head)) return map[head];
        Node* cp = new Node(head->val);
        map[head] = cp;
        cp->next = copyRandomList(head->next);
        cp->random  = map[head->random];
        return cp;
        
    }
};
