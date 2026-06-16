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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* cur = head;
        int g =0;
        while(cur != nullptr && g < k)
        {
            cur = cur->next;
            g++;
        }
        if( g == k)
        {
         cur = reverseKGroup(cur,k);
         while( g-- > 0)
         {
            ListNode* tmp = head->next;
            head->next = cur;
            cur = head;
            head = tmp;
         }
         head = cur;
        }
        return head;
    }
};
