class Solution {
public:
    int maxDepth(TreeNode* root) {
        
        if(!root){
            return 0;
        }
            
        int depth = 1;
        // make a pair of the node ptr and its depth
        stack<pair<TreeNode*, int>> track;
        // push root,1
        track.push({root, depth});
 
        while(!track.empty()){
            
            int curr = get<1>(track.top());
            // @ each dfs iteration
            // take max with curr depth
            depth = max(depth, curr);
            TreeNode* node = get<0>(track.top());
            track.pop();
            
            // push the next level nodes into the stack
            // with depth = curr depth + 1
            if(node->right != nullptr){
                track.push({node->right,curr+1});
            } 

            if(node->left != nullptr){
                track.push({node->left, curr+1});
            } 
        }        
        
        
        return depth;
        
    }
};
    
