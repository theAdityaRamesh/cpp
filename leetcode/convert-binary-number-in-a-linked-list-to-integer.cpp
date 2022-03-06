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
    int getDecimalValue(ListNode* head) {
        int ans = 0;
        // we do a left shift 
        // everytime we get a new linked list node
        while(head){
            ans <<= 1; // so left shift by 1
            ans += 2*(head->val&1); // add 2 or 0
            head = head->next; // move the head
        }
        
        return ans/2;
        
    }
};
