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
 
 // basically DFS
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        
        if(!root){
            return {};
        }
        
        vector<int> res;
        
        stack<TreeNode*> track;
        track.push(root);
        
        while(!track.empty()){
            res.push_back(track.top()->val);
            
            TreeNode* top = track.top();
            track.pop();
            
            if(top->right){
                track.push(top->right);
            }
            
            
            if(top->left){
                track.push(top->left);
            }
            
        }
        
        return res;
    }
};
