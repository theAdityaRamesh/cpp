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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        // create dummy node
        ListNode* dummy = new ListNode;
        dummy->val = INT_MAX;
        dummy->next = nullptr;
        // head points to the sorted list
        ListNode* head = dummy;
        // head is the last node of the sorted list
        
        while(list1 && list2){           
            // if list1 has the smaller value
            if(list1->val <= list2->val){
                // insert the list1 node after head
                head->next = list1;
                // move the list1 pointer ahead
                list1 = list1->next;
                // disconnect the list1 node added to the sorted list
                // from list1
                head->next->next = nullptr;
            } else {
                // point head to the list2 node
                head->next = list2;
                // move the list2 ptr ahead
                list2 = list2->next;
                // disconnect the list2 node added to the sorted list
                // from list 2
                head->next->next = nullptr;
            } head = head->next;
        
        }
        
        // if list1 is longer
        // add the list 1 nodes after the head
        if(list1){
            head->next = list1;
        }
        
        // if list2 is longer
        // add the remaining list2 nodes after the head
        if(list2){
            head->next = list2;
        }
        
        // remove the dummy node
        dummy = dummy->next;
        return dummy;
    }
};
