
class Solution {
public:
    void deleteNode(ListNode* node) {
        // we are given the node to be deleted directly
        // so we cant break the prev connection
        // so only way is to shift the value to the end and
        // discard it
        // like insertion sort
        
        ListNode* prev = node;
        ListNode* next = node->next;
        while(next->next){
            // shift value of next node into prev
            prev->val = next->val;
            // shift prev and next forward
            prev = prev->next;
            next = next->next;
        }
        // next->next will break when next is the last node
        // we break before the end of list because we dont need the last node
        // as we are deleting one node
        // if dont prev will becom the last node and next will be null
        // so we have no way of deleting the last node
        prev->val = next->val;
        prev->next = nullptr;
    }
};
