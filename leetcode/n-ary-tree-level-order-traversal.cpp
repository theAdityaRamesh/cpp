/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        
        vector<vector<int>> ans; // ans vector
        queue<Node*> track; // queue to travel in level order
        track.push(root);
        track.push(nullptr); // we use nullptr to indicate change in level
        ans.push_back({});
        
        while(!track.empty()){
            Node* curr = track.front();
            track.pop();
            
            if(curr == nullptr){
                break;
            } 
            
            for(auto child : curr->children){
                track.push(child);
            } 
            
            ans.back().push_back(curr->val);
            
            // if after curr node the next node is a nullptr
            // it means the grandparent must have pushed it after the last child
            // ie : the current node is the last in line in the prev generation
            // hence it indicates a change in level
            if(track.front() == nullptr){
                track.push(nullptr);
                track.pop();
                ans.push_back({});
            
            }
        }
        
        ans.pop_back();
        return ans;
    }
};
