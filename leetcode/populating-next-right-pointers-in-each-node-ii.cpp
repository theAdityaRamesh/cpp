// this question can be done easilt using normal BFS
// but since we have the next pointer
// we can use it instead of a Q
class Solution {
public:
    Node* connect(Node* root) {
        
        if(!root){
            return root;
        }
        
        Node* parent = root;
        Node* start = nullptr;
        Node* next = nullptr;
        
        while(parent){
            
            // if parent->left exists
            if(parent->left){
                if(next){ // if we have a valid next pointer
                    // it must be the previous parent's righ child
                    // or any child of a previous parent
                    next->next = parent->left;
                    // assigne the next to the current left child
                    // as it is the nearest child to it in that level
                    next = next->next;
                    // move next to the newly linkef child
                    // ie next = parent->left now
                } else{
                    // if we have a null next
                    // it means we are searching for the next node 
                    // at that level
                    // since parent->left has been found
                    // next is now parent->left
                    // start is also now parent as
                    // either this is the start of the new level
                    // or the previous parents dont have children
                    // so we move the start ahead
                    next = parent->left;
                    start = parent->left;
                }
            } 
            
            // same for right node
            if(parent->right){
                if(next){
                    next->next = parent->right;
                    next = next->next;
                } else{
                    next = parent->right;
                    start = parent->right;
                }
            }
                
            // here we first make an assignment in the if cond
            // then we compare
            // if there are no more parents at the prev level
            // its time for the leftmost child to become new parents
            // and start over from there
            if(!(parent = parent->next)){
                // we reset the start and next
                // so that it gets set in the next iterations
                parent = start;
                start = nullptr;
                next = nullptr;
            }
        }
        
        return root;
    }
};
