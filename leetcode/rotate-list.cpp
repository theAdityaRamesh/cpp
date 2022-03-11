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
    ListNode* rotateRight(ListNode* head, int k) {
        
        // if empty list or num shifts is zero
        // return the same list
        if(!head || k == 0){
            return head;
        }
        
        // store the head
        ListNode* prev = head;
        int size = 0;

        // traverse the list once to find its length
        while(head->next){
            size++;
            head = head->next;
        }
        
        // connect the tail and head nodes
        head->next = prev;
        head = prev;
        
        // scale the k to be within [0,size]
        k = k%(size+1);
        
        // now we need to go to the n-k-1 th node
        // and sever the next connection
        // then return the n-k th node as the new head
        while(size - k > 0 ){
            size--;
            head = head->next;
        }
        
        prev = head;
        head = head->next;
        prev->next = nullptr;
        return head;
    }
};
