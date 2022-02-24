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
        
        if(head == nullptr || head->next == nullptr){
            return false;
        } // if only 1 node or no node no cycle
        // return false
            
            // fast travels at 2 nodes/iteration
            // slow travels at 1 nodes/iteration
            // so for N nodes in a cycle
            // every N/2 iterations fast and slow will meet
        
            ListNode* slow = head;
            ListNode* fast = head;
            while(fast->next && fast->next->next){
                slow = slow->next;
                fast = fast->next->next;
                if(slow == fast){
                    return true;
                }
            }
        
        return false;
    }
};
