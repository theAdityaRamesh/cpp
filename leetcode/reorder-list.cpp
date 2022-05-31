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
    void reorderList(ListNode* head) {
        rearrange(head, head);
    }
    
private:
    
    ListNode* rearrange(ListNode* front, ListNode* head){
        
        // maintain 2 pointers head and front
        // go to the end of the list
        // head is now at the last node
        // we take the last node and connect it to the second node
        // using the front node
        // then connect front node to the last node
        // now we move the front node forwards
        // adn back node backwards towards the start by
        // unrolling the recursion stack
        
        if(head->next != nullptr){
            front = rearrange(front, head->next);
        }
        
        if(front != nullptr){   
            if(head == front->next || front == head){
                head->next = nullptr;
                front = nullptr;
            } else {
                head->next = front->next;
                front->next = head;
                front = head->next;  
            }
        } 
        
        return front;
    }
    
};
