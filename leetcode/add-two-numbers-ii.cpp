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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int size_l1 = 0;
        int size_l2 = 0;
        
        ListNode* temp = l1;
        while(temp != nullptr){
            temp = temp->next;
            ++size_l1;
        }
        
        temp = l2;
        while(temp != nullptr){
            temp = temp->next;
            ++size_l2;
        }
        
        // assume l1 is larger list otherwise swap
        if(size_l1 < size_l2){
            swap(size_l1, size_l2);
            swap(l1, l2);
        }
        
        pair<ListNode*, int> node = add(size_l1, size_l2, l1, l2);
        
        // add extra nodes for carry 
        // when ans is larger than the list
        while(node.second != 0){
            ListNode* newNode = new ListNode(node.second%10, node.first);
            node.first = newNode;
            node.second /= 10;
        }
        
        // return head
        return node.first;
    }
    
private:
    
    // use the call stack to recurse on the list
    pair<ListNode*,int> add(int size_l1, int size_l2, ListNode* l1, ListNode* l2){
        
        // count the sizes of the list 
        // so that we skip nodes till we have equal place
        // values
        /// recurse thru the list till the last node
        // while unrolling the stack
        // return the carry from the prev step
        // and the prev node
        // in each step make a new node and connect it to the 
        // node returned in the prev step
        pair<ListNode*, int> prev;
        prev.first = nullptr;
        prev.second = 0;

        if(size_l1 > 1 && size_l2 >= 1){
            if(size_l1 > size_l2){
                prev = add(size_l1-1, size_l2, l1->next, l2);
            } else{
                prev = add(size_l1-1, size_l2-1, l1->next, l2->next);
            }
        }
        
        if(size_l1 == size_l2){
            prev.second += l1->val+l2->val;
        } else{
            prev.second += l1->val;
        }
        
        ListNode* node = new ListNode(prev.second%10, prev.first);     
        return {node, prev.second/10};
    }
    
};
