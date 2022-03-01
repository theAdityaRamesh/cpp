// recursive implementation

class Solution {
public:
    
    bool check(TreeNode* root, TreeNode* subRoot){
        
        if(root == nullptr && subRoot == nullptr){
            return true;
        } else if( !root || !subRoot ){
            return false;
        }
        
        if(root->val == subRoot->val){
            bool left = check(root->left, subRoot->left);
            bool right = check(root->right, subRoot->right);
            return left && right;
        } else{
            return false;
        }
    }
    
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        // if root is null return false
        // either empty tree
        // or we reached the end of tree
//         because no matches found
        if(!root){
            return false;
        }
//       otherwise if the value of root and subroot are same
//         and the subtree is also starting from this node
//         return true because subtree found
        if(root->val == subRoot->val && check(root, subRoot)){
            return true;
        } else {
//             otherwise
//               go left and go right 
//           return either subtree found in left or right
            return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
        }
        
        
    }
};


// iterative implementation
class Solution {
public:
    
    // check function same 
    // iterate thru tree and subtree together
    // if at any step value mismatch
    // or if either of them goes to null
    // while other is not null
    // return false
    bool check(TreeNode* root, TreeNode* subRoot){
        
        if(root == nullptr && subRoot == nullptr){
            return true;
        } else if( (root == nullptr && subRoot != nullptr) || (root != nullptr && subRoot == nullptr) ){
            return false;
        }
        
        if(root->val == subRoot->val){
            bool left = check(root->left, subRoot->left);
            bool right = check(root->right, subRoot->right);
            return left && right;
        } else{
            return false;
        }
    }
    
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        
        // traverse tree using stack
        stack<TreeNode*> traverse;
        traverse.push(root);
        bool ans = false;
        while(!traverse.empty()){
            TreeNode* top = traverse.top();
            traverse.pop();
            
            // if at any root we find value to subroot's root
            if(top->val == subRoot->val){
                // check for subtree
                ans = check(top, subRoot);
                if(ans){
                    // if subtree found return true
                    return ans;
                }
            }
            
            // otherwise go left and right
            if(top->left != nullptr){
                traverse.push(top->left);
            }
            
            if(top->right != nullptr){
                traverse.push(top->right);
            }
            
        }
        
        return ans;
    }
};
