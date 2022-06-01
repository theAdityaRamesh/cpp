// https://leetcode.com/problems/add-two-numbers/


// m1 - create new nodes tp store ans
// struct ListNode {
//       int val;
//       ListNode *next;
//       ListNode() : val(0), next(nullptr) {}
//       ListNode(int x) : val(x), next(nullptr) {}
//       ListNode(int x, ListNode *next) : val(x), next(next) {}
//  };
 
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode* head = new ListNode;
        ListNode* current = head;
        bool headFlag = true;
        int sum=0,sum1=0,sum2 = 0, carry = 0;
        
        while(l1 != nullptr || l2!= nullptr){
        
            if(l1 != nullptr){
                sum1 = ((*l1).val); l1 = (*l1).next;}
                else {sum1 = 0; l1 = nullptr;}
            
            if(l2 != nullptr){
                sum2 = ((*l2).val); l2 = (*l2).next;
            } else {sum2 = 0; l2 = nullptr;}
            
            sum = (sum1 + sum2 + carry);
            if (sum >= 10){
                sum = sum%10;
                carry = 1;
            } else
                carry = 0;
                       
            if (headFlag == true){
                (*head).val = sum;
                headFlag = false;
            } else {
                
                ListNode* nextNode = new ListNode(sum);
                (*current).next = nextNode;
                current = nextNode;
            }
                         
        } 
        
        if(carry != 0){
            ListNode* nextNode = new ListNode(1);
            (*current).next = nextNode;
        }
        
        return head;
    }
};

// inplace ans storage

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
        
        ListNode* head =l1;
        int ans = 0;
        while(l1->next && l2->next){
            ans += l1->val + l2->val;
            l1->val = ans%10;
            ans /= 10;
            l1 = l1->next;
            l2 = l2->next;
        }
        
        // connect l1 to l2 is l2 is shorter
        if(!l1->next && l2->next){
            l1->next = l2->next;
        }
    
        ans += l1->val + l2->val;
        l1->val = ans%10;
        ans /= 10;
        
        while(ans != 0 && l1->next){
            ans += l1->next->val;
            l1->next->val = ans%10;
            ans /= 10;
            l1 = l1->next;
        }
        
        
        while(ans != 0){
            ListNode* node = new ListNode;
            node->val = ans%10;
            node->next = nullptr;
            l1->next = node;
            l1 = node;
            ans /= 10;
        }
        
        
        
        return head;
    }
};
