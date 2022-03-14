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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        
        // p XOR q
        // if one null and other not null
        // p XOR q is true
        // hence invalud tree
        // return false
        if(!p != !q){
            return false;
        }
        
        // if both null ptr
        // valid tree
        // return true
        if(!p && !q){
            return true;
        }
        
        // check node left and right
        return (p->val == q->val) && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
        
    }
};
