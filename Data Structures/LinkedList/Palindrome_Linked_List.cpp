//https://leetcode.com/problems/palindrome-linked-list/

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
    ListNode* temp;
    bool isPalindrome(ListNode* head) {
        temp = head;
        return checkPal(head);
        
    }
    
    bool checkPal(ListNode* p){
        if(p==NULL)
            return true;
        
        bool pal = checkPal(p->next) && (temp->val == p->val);
        
        temp = temp->next;
        return pal;
    }
};
