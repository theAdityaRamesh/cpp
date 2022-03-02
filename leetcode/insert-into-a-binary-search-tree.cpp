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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        // for empty tree
        if(root == nullptr){
            TreeNode* root = new TreeNode;
            root->val = val;
            root->left = nullptr;
            root->right = nullptr;
            return root;
        }
        
        // if val > root go right
        if(val > root->val){
            if(root->right == nullptr){
                root->right = new TreeNode;
                root->right->val = val;
                root->right->right = nullptr;
                root->right->left = nullptr;
            } else {
                insertIntoBST(root->right, val);
            }
        } else{ // else go left
            if(root->left == nullptr){
                root->left = new TreeNode;
                root->left->val = val;
                root->left->right = nullptr;
                root->left->left = nullptr;
            } else{
                insertIntoBST(root->left, val);
            }
        }
        
        return root;
    }
};
