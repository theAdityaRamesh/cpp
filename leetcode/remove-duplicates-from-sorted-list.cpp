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

void deleteDupli(ListNode* head, ListNode* next){
    
    if(head == nullptr){
        return;
    }
    
    if(next == nullptr){
        head->next = next;
        return;
    }
    
    if(next->val == head->val){
        deleteDupli(head,next->next);
    } else{
        head->next = next;
        deleteDupli(next,next->next);
    }
}

    
ListNode* deleteDuplicates(ListNode* head){
    
    if(head != nullptr){
        deleteDupli(head,head->next);
    }
    return head;
}
    
    ListNode* deleteDuplicates(ListNode* head) {
        
        ListNode* dummy = new ListNode;
        dummy->next = head;
        ListNode* prev = dummy;
        
        // while head not null keep scanning
        while(head){
            // prev is node before head
            // till we find a node that is not 
            // equal to current value move head 
            // forward
            while(head && head->val == prev->next->val){
                head = head->next;
            }
            
            // if next node itself is unique
            // ie no duplicates
            // move prev forward
            if(prev->next->next == head){
                prev = prev->next;
            } else {
                //otherwise
                // break the conncection
                // connect with new pos of 
                // head
                prev->next->next = head;
                prev = prev->next;
            }
        }
        
        return dummy->next;
    }
};
