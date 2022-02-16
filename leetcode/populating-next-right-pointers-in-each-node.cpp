/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/
class Solution {
public:
    
   
    Node* connect(Node* root) {
        
        if(root == nullptr){
            return root;
        }
        
        Node* rightNull = root;
        queue<Node*> track;
        track.push(root); // move in BFS using queue
        
        while(!track.empty()) {
            
            Node* temp = track.front();
            track.pop(); // get the oldest element
            
            temp->next = track.front(); // conncet it with next element in the same level
            
            if(temp == rightNull){
                temp->next = nullptr; // if we have reached end of level 
                rightNull = rightNull->right; // conncet null
            } // move the end of level pointer
   
            if(temp->right != nullptr){ // push children of the node in queue
                track.push(temp->left);
                track.push(temp->right);
            }
            
        }
        
                    
                     
       return root;  
    }

};
