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
    TreeNode* invertTree(TreeNode* root) {
        
        // empty tree
        if(!root){
            return root;
        }
        
        // maintain queue of nodes
        queue<TreeNode*> invert;
        // here we need to assume that the parent is already
        // in the correct position and swap the children
        // we begin by swwapping the root's children
        // we then have inverted the tree at the first level
        // and put the nodes in therir correct places
        // we then push the children who will be parents next
        // and then swap therir children
        swap(root->left, root->right);
        invert.push(root->left);
        invert.push(root->right);
        
        while(!invert.empty()){
            TreeNode* front = invert.front();
            invert.pop();
            if(front != nullptr){
                swap(front->left, front->right);
                invert.push(front->left);
                invert.push(front->right);
            }
        }
        
        return root;
    }
};
