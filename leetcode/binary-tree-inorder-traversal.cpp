// better solution using extra pointer
// no need to modify the tree as well

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        
        if(!root){
            return {};
        }
        
        stack <TreeNode*> S;
        vector <int> res;
        TreeNode* temp = root;
            
        while((!S.empty())||(temp != NULL)){
          // go to the deepest part of the left subtree
          if(temp != NULL){
                S.push(temp);
                // keep changing the ptr to the left tree
                temp = temp->left;                
            }
            else{
                // pop the top node
                // mark as temp
                temp = S.top();
                S.pop();
                res.push_back(temp->val);
                // if the top node is a child the temp will be null
                // it will keep being null till we reach a node with a right sub tree
                // when we reach that node
                // we go right 
                // and then go to the deepest part of the left subtree of the right node
                temp = temp->right;
            }
        }
        return res;        
    }
};

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
    vector<int> inorderTraversal(TreeNode* root) {
        
        if(!root){
            return {};
        }
        
        vector<int> res;
        stack<TreeNode*> track;
        track.push(root);
        // in question its give node.val is b/w -100 and 100
        
        while(!track.empty()){
            // pop the top node
            TreeNode* node = track.top();
            track.pop();

            if(node && !node->left && !node->right){
                // if child node push into result
                res.push_back(node->val);
            } else {// otherwise
                    // if already visited
                    if(node->val > 100){
                        // push into result
                        res.push_back(node->val-201);
                    } else {// otherwise
                        // mark node as visited
                        // by increasing the val by 201
                        // since val is b/w -100 and 100
                        node->val = node->val + 201;
                        
                        // inorder is Left=Root=Right
                        // so push right first
                        if(node->right){
                            track.push(node->right);
                        }
                        
                        // push node
                        track.push(node);
                        
                        // push left
                        if(node->left){
                            track.push(node->left);
                        }
                        
                        // now in next iteration we'll push the node into result
                        // as it has not been marked as visited.
                    }
            }
        }
            
            
        
        return res;
    }
};
