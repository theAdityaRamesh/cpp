//leetcode.com/problems/remove-nth-node-from-end-of-list/

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        
        ListNode* leadPtr = head;
        ListNode* trailPtr = head;
        
        while(n){
            leadPtr = leadPtr->next;
            n--;
        }
        
        // case : n = size leadPtr == null
        if(leadPtr == nullptr){
            return head->next;
        }
        
        while(leadPtr->next != nullptr){leadPtr = leadPtr->next; trailPtr = trailPtr->next;}
        trailPtr->next = trailPtr->next->next;
        
        return head;
    }
};
