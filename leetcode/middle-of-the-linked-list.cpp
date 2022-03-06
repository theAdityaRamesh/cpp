class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        
        
        
        ListNode* fast = head;
        ListNode* slow = head;
        
        // fast moves at speed of 2 nodes/iteration
        // slow moves at 1 node/iteration
        // so when fast is at Nth node in N/2th iteration
        // slow is at N/2th node in N/2th iteration
        
        while(fast && fast->next){
            fast = fast->next->next;
            slow = slow->next;
        }
        
       
        return slow;
    }
};
