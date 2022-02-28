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
    
    
    
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        if(!root){
            return {};
        }
            
        vector<vector<int>> res;
        queue<TreeNode*> track;
        // declare left most pointer
        TreeNode* leftMost = nullptr;
        track.push(root);
        vector<int> level;
 
        
        while(!track.empty()){
            // take the top of queue
            TreeNode* node = track.front();
            track.pop();
            
            // if the leftMost is null that means
            // the left subtree dne after that level
            // hence we need to update it at the next non null node
            // int the Q
            if(leftMost == nullptr){
                // we take node->left to be leftMost 
                if(node->left != nullptr){
                    leftMost = node->left;
                // if that is not available take the right
                } else if(node->right != nullptr){
                    leftMost = node->right;
                }
            }
            
            // when ever we reach the leftmost node
            // it means we have completely searched the previous level
            // hence push the lvel to the res vector
            // and clear the level vector for the new nodes
            if(node == leftMost){
                res.push_back(level);
                level.clear();
                if(leftMost->left != nullptr){
                    leftMost = leftMost->left;
                } else{
                    leftMost = leftMost->right;
                }
            }
            
            // add new nodes to level
            level.push_back(node->val);
            
            // add the new nodes to the Q
            if(node->left!= nullptr){
                track.push(node->left);
            } 
            
            if(node->right != nullptr){
                track.push(node->right);
            }
            
            
        }
        
        // at the end of the tree
        // we dont have any further level
        // hence we will never reach leftMOst
        // hecne push the level to the ans vector
        if(!level.empty()){
            res.push_back(level);
        }

            
                
        return res;
        
    }
};
