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
    ListNode* reverseList(ListNode* head) {
        
        if(head == nullptr || head->next == nullptr){
            return head;
        }
        
        ListNode* front = reverseList(head->next);
        head->next->next = head; // make the next point to prev
        head->next = nullptr; // cut prev node forward conn
        return front;
    }
};


//1 -> 2 -> 3 -> 4 -> 5 
// 1->2->3->4 5->4
// 1->2->3  5->4->3
// 1->2 5->4->3->2
//1 5->4->3->2->1
