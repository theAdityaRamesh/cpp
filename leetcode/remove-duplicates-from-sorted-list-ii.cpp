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
    ListNode* deleteDuplicates(ListNode* head) {
        
        // create a dummy node
        ListNode* ans = new ListNode;
        // point it to the current head
        ans->next = head;
        // point the prev ptr to dummy
        ListNode* prev = ans;
        
        while(head){
            // skip nodes till the value changes
            int curr = head->val;
            while(head && head->val == curr){
                head = head->next;
            } 
            
            // if the next node itself is unique
            if(head == prev->next->next){
                // move prev by 1 step
                // head already moved forward
                prev = prev->next;
            } else{
                // if we are not at the next node
                // dont move prev
                // point prev to new head position
                prev->next = head;
            }
        }
        
        // remove dummy 
        // return next after dummy
        return ans->next;
    }
};
