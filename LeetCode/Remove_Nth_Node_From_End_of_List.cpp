//https://leetcode.com/problems/remove-nth-node-from-end-of-list/

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        ListNode x(0);
        x.next=head;
        
        ListNode *slow = &x,*fast=&x;
        
        for(int i=0;i<n;i++)
            fast = fast->next;
        
        while(fast->next){
            slow = slow->next;
            fast = fast->next;
        }
        
        ListNode* toBeDeleted = slow->next;
        slow->next = slow->next->next;
        
        delete toBeDeleted;
        
        return x.next;
        
    }
};
