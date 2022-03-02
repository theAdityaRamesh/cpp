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
    TreeNode* searchBST(TreeNode* root, int val) {
        
        // in a binary search tree
        // right > root > left
        // so move thru the tree according to that
        // no need to check all the paths
        
        if(!root){
            return nullptr;
        }
        
        if(root->val == val){
            return root;
        } else if(root->val > val){
            return searchBST(root->left, val);
        }  else{
            return searchBST(root->right, val);
        }
    }
};
