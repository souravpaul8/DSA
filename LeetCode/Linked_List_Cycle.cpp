//https://leetcode.com/problems/linked-list-cycle/

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
    bool hasCycle(ListNode *head) {
        ListNode *walker = head,*runner = head;
        
        while(walker && runner && runner->next){
            walker = walker->next;
            runner = runner->next->next;
            
            if(runner==walker)
                return true;
        }
        
        return false;
    }
};
