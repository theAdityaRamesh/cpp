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
    bool isSymmetric(TreeNode* root) {
        
        // basically consider root->left and root->right as
        // 2 seperate trees
        // then check both of them
        
        stack<TreeNode*> left;
        stack<TreeNode*> right;       
        
        if(root->left != nullptr){
            left.push(root->left);
        }
        
        if(root->right != nullptr){
            right.push(root->right);
        }
        
        while(!left.empty() && !right.empty()){
            
            TreeNode* pL = left.top();
            TreeNode* pR = right.top();
            left.pop();
            right.pop();
            
            if(pL->val != pR->val){
                return false;
            }
            
            
            // due to mirror image
            //leftTree moves right so rightTree ptr moves left
            if(pL->right != nullptr && pR->left != nullptr){
                left.push(pL->right);
                right.push(pR->left);
            } else if((pL->right != nullptr) != (pR->left != nullptr)){
                return false;
            }
            
            //leftTree moves left so righTree moves right
            if(pL->left != nullptr && pR->right != nullptr){
                left.push(pL->left);
                right.push(pR->right);
            } else if((pL->left != nullptr) != (pR->right != nullptr)){
                return false;
            }
            
        }
        
        // if one of the stacks is smakker
        // less nodes in one of the trees
        if(!left.empty() && right.empty()){
            return false;
        }
        
        if(!right.empty() && left.empty()){
            return false;
        }
        
        return true;
    }
};
