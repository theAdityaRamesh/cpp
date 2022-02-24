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
    ListNode* removeElements(ListNode* head, int val) {
        
        ListNode* dummy = new ListNode;
        dummy->next = head;
        ListNode* prev = dummy;
        
        while(head){
            // if head is val
            if(head->val == val){
                // if head not null
                // skip till !val found
                while(head && head->val == val){
                    head = head->next;
                }
                // make prev pointer point to !val
                prev->next = head;
            } else {
                // otherwise
                // move prev
                // move head
                prev = prev->next;
                head = head->next;
            }
        }
        
        // disconnect dummy node
        return dummy->next;
    }
};
