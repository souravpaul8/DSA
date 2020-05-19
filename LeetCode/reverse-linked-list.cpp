//https://leetcode.com/problems/reverse-linked-list/


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
    ListNode* reverseList(ListNode* head) {
        ListNode  *prev=NULL,*current=head,*next;
        while(current!=NULL){
            next = current->next;
            current->next =prev;
            prev = current;
            current = next;
        }
        
        head = prev;
        
        return head;
    }
};