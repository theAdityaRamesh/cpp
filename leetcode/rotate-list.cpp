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
        
        // if no nodes or single node
        // return the head
        if(!head || !head->next){
            return head;
        }

        // get list size
        // use list size operation
        // to get the last node as well
        // by passing a reference to a pointer
        int list_size = 0;
        ListNode* last = head;
        list_size = get_size(last);
        
        k %= list_size;
        // if k = 0 we dont have to rotate
        if(k == 0){
            return head;
        }
        
        // take the last node connect it to the first node
        last->next = head;
        
        // sever the connection b/w the n-k-1th node and n-kth node
        // return n-kth node as new head
        list_size -= (k+1);
        while(list_size){
            head = head->next;
            list_size--;
        }
        
        last = head->next;
        head->next = nullptr;
        
        return last;
    }
    
private:
    
    int get_size(ListNode*& head){
        int ans = 0;
        while(head->next){
            ++ans;
            head = head->next;
        }
        return ans+1;
    }
    
};
