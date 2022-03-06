
class Solution {
public:
    
    void getSum(TreeNode* root, int& sum){
        if(root){
            // a left leaf is left of parent of a child node
            // and the child node has no children
            // if we find such a node
            // add the sum
            if(root->left && !root->left->left && !root->left->right){
                sum += root->left->val;
            }   
            
            // otherwise
            // go left
            // go right
            getSum(root->left, sum);
            getSum(root->right, sum);
        }
    }
    
    int sumOfLeftLeaves(TreeNode* root) {
        
        int sum = 0;
        getSum(root, sum);
        return sum;
    }
};
