
class Solution {
public:
    // recursive implementation
    //till the head->next is not null
    //go forward in the list
    //when we reach end of the list compare it to the front ptr value
    //intitally assume list is a palindrome so ans is set to true
    //once we find a false dont update the ans
    //each time return the next node in the list to compare wiht the reversed list
    //return the ans finally
    ListNode* check(ListNode* head, ListNode* front, bool& ans){
        
        if(head->next){
            front = check(head->next, front, ans);
        }
        ans = ans ? (front->val == head->val) : ans;
        return front->next;
    }
    
    
    // non recursive implementation
    // 1->2->2->2->1 say is the list
    // keep a fast and slow pointer
    // reverse the list as we travel it
    // 1<-2  2->2->1
    // 1<-2<-2  2->1 
    // then compare the list while travelling back and front from the centre
    bool isPalindrome(ListNode* head) {
        
        // if only one node
        if(head->next == nullptr){
            return true;
        }
        
        
        
        ListNode* slow = head;
        ListNode* dummy  = new ListNode;
        // create a dummy node before the head
        // call it prev
        dummy->next = head;
        ListNode* prev = dummy;
        ListNode* fast = head;
        ListNode* temp;
        
        // fast->next && fast->next->next because
        // for odd size fast will end up @ the last node of the list
        //for even size fast will end up 1 before the last node

        while(fast->next && fast->next->next){
            
            // move the fast node forward
            fast = fast->next;
            fast = fast->next;
            
            // keep track of curr node
            temp = slow;
            // shift it forward
            slow = slow->next;
            // break the next connection to the next node
            // point it to the prev node
            temp->next = prev;
            // call current node prev henceforth
            prev = temp;
        } 
        
        // if list has only 2 nodes
        if(fast == head){
            // return if first node is equal to second
            return head->val == head->next->val;
        }
        
        
        // remove the dummy node by cutting the connection
        // make it nullptr
        dummy->next->next = nullptr;
        if(fast->next == nullptr){
            // if fast->next is null it means
            // we have a odd size list
            // so we have a centre node
            // slow is currently at the centre node
            // prev is the node before it
            // so move slow by one step
            slow = slow->next;
        } else{
            // if we have a even size list
            // fast is at the node before the end
            // slow is at (N/2)th node
            // so we still need to make one more reverse connection
            // so we point the N/2 node to its prev node
            // and shift slow forward
            // and prev forward
            // so prev is at the N/2 node and slow at N/2+1 node
            // so prev and slow are at the 2 centres of the list
            temp = slow;
            slow = slow->next;
            temp->next = prev;
            prev = temp;
        }
        
        
        // now compare the prev and slow nodes
        // and break immediately if we find mismatch
        // otherwise move prev backwards and slow forwards
        while(prev && slow){
            if(prev->val != slow->val){
                return false;
            } prev = prev->next;
            slow = slow->next;
        }        
        
        return true;
    }
};
