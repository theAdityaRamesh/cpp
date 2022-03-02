class Solution {
public:
    vector<int> preorder(Node* root) {
        
        if(!root){
            return {};
        }
        
        vector<int> ans;
        stack<Node*> traverse;
        traverse.push(root);
        
        while(!traverse.empty()){
            
            Node* top = traverse.top();
            traverse.pop();
            ans.push_back(top->val);
            // traverse the children from right to left
            // hence iterate thru the vector from
            // back to front
            auto it = top->children.rbegin();
            for(; it != top->children.rend(); it++){
                if(*it != nullptr){
                    traverse.push(*it);
                }
            }
            
        }
       
        return ans;
        
    }
};
