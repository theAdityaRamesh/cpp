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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isSubPath(ListNode* head, TreeNode* root) {
            
        // if there is no node then we cant do any checking
        // return false
        if(root == nullptr){return false;} 
        // search starting from the current node
        // search in the left sub tree
        // search in the right sub tree
        // if even in one place we find the pattern we return true
        return search(head,root) or isSubPath(head, root->left) or isSubPath(head, root->right);
    }
    
private:
    bool search(ListNode* head, TreeNode* root){
        
        // if we reached the end of the list 
        // then we return true
        
        if(head == nullptr){
            return true;
        }
        
        // if there is no node we cant search
        // return false
        if(root == nullptr){
            return false;
        }
        
        // validate the current node for equality
        // go left go right and continue the pattern
        return (head->val == root->val) and (search(head->next, root->left) or search(head->next, root->right));
    }
    
};
