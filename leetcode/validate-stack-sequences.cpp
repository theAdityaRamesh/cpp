class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
               
        int tos = 0; // Top Of Stack ptr
        int last_pushed = 1; // last pushed ptr
        for(int pop : popped){
            
            // logic is if TOS is equal to the current pop
            // remove it by marking as INT_MIN and then 
            // move the TOS ptr back
            // otherwise element is not in the stack
            // we have to push till we get the element
            // and move the TOS ptr forward from the last 
            // pushed ptr
            
            if(tos >= 0 && pushed[tos] == pop){
                pushed[tos] = INT_MIN;
            } else {
                tos = last_pushed;
                while(last_pushed < pushed.size() && pushed[last_pushed] != pop){
                    last_pushed++;
                    tos++;
                }
                
                if(tos == pushed.size()){return false;}
                pushed[tos] = INT_MIN;
            }
            
            while(tos >= 0 && pushed[tos] == INT_MIN){
                tos--;
            }
            
        }
        
        return true;
    }
};
