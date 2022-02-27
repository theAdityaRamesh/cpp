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
    vector<int> postorderTraversal(TreeNode* root) {
        
        if(!root){
            return {};
        } // if empty tree return empty
        
        vector<int> res;
        stack<TreeNode*> track;
        track.push(root);
        // push root into stack  
      
        while(!track.empty()){
            // top node is 
            TreeNode* node = track.top();
            if(node == nullptr){
                // if top node is nullptr
                // it means we have visited all the chidren of the parent
                // now we can visit parent as well
                track.pop();
                res.push_back(track.top()->val);
                track.pop();
            } else{
                // otherwise 
                // we have not visited all the children of the parent
                // so mark as parent by pushing a nullptr above the node
                // then push the left and right subtrees
                track.push(nullptr);
                if(node->right != nullptr){
                    track.push(node->right);
                } 
                
                if(node->left != nullptr){
                    track.push(node->left);
                }
            }
        }
                
        return res;
    }
};
