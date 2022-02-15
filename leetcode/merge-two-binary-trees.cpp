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
    
    void merge(TreeNode* root1, TreeNode* root2){
        
        if(root2 == nullptr){
            return; // if second tree is empty return
        }
        
        if(root1 != nullptr && root2 != nullptr){
            root1->val = root1->val + root2->val;
        } // if both trees are nonempty 
        // edit first tree node to sum of the 2
        
         // if second tree is non empty
        // and first tree is empty
        // take second tree nodes and attach to first tree
       // make second tree next = null
        if(root1->left == nullptr && root2->left != nullptr){
            root1->left = root2->left;
            root2->left = nullptr;
        } 
        
        if(root1->right == nullptr && root2->right != nullptr){
            root1->right = root2->right; // attach to first tree
            root2->right = nullptr; // detach from 2nd tree
        }
        
        merge(root1->right, root2->right); // go left
        merge(root1->left, root2->left); // go right
        return;
        
    }
    
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        
        if(root1 == nullptr){
            return root2;
        } 
        
        if(root2 == nullptr){
            return root1;
        }
        
        // if any of the trees are empty return the other
      
        // otherwise merge
        merge(root1, root2);
        
        return root1;
    }
};
