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

// iterate using DFS
// recursive implementation
bool hasPathSum(TreeNode* root, int target) {

    if(!root){
        return false;
    }
    
    if(root->left == nullptr && root->right == nullptr && (target-root->val) == 0){
        return true;
    }
    
    bool left = hasPathSum(root->left, target-root->val);
    bool right = hasPathSum(root->right, target-root->val);
    return left || right;
}
    
    
// iterative implementation
    bool hasPathSum(TreeNode* root, int target) {
        bool ans = false;
        stack<pair<TreeNode*,int>> sum;
        
        if(!root){
            return ans;
        }
        
        sum.push({root,0});
        
        while(!sum.empty()){
            TreeNode* curr = get<0>(sum.top());
            int currSum = get<1>(sum.top());
            sum.pop();
            
            currSum += curr->val;
            // check if current node is a leaf node
            if(currSum == target && curr->left == nullptr && curr->right == nullptr){
                ans = true;
                break;
            } else {
              // otherwise push the children
                if(curr->right != nullptr){
                    sum.push({curr->right, currSum});
                }                
                
                if(curr->left != nullptr){
                    sum.push({curr->left, currSum});
                }
            }
        }
        
        
        return ans;
    }
};
