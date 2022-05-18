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
    
    int height(TreeNode* root, bool& ans){
        
        // if we have reached null node 
        // no height so return 0
        // if we found unbalenced node just
        // return 0 unroll the stack.
        if(root == nullptr || !ans){
            return 0;
        }
        
        // we go left then we go right
        // @ each node get the left tree height
        // and right tree height and store it
        int h_left = height(root->left, ans);
        int h_right = height(root->right, ans);
        // if still the tree is balanced then 
        // update ans
        if(ans){
            ans = (abs(h_left-h_right) < 2);
        }
        
        // return the height and add 1 for the 
        // current node.
        return max(h_left, h_right) + 1;        
    }
    
    bool isBalanced(TreeNode* root) {
        
        bool ans = true; // create a variable to store ans
        height(root, ans); // recusrsively travel tree
        return ans; // return ans
    }
};
