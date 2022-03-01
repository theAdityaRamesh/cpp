class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        
        vector<int> alphabet(26,0);
        int unequalIndx = -1;
        int size = s1.size();
        int cnt = 0;
        
        // if only one char
        // if its equal return true
        // else return false
        if(size == 1 && s1[0] != s2[0]){
            return false;
        }
        
        // scan from left to right
        for(int i = 0; i < size; i++){
            if(s1[i] != s2[i]){
                // if mismatch found 
                if(cnt == 1){return false;} // check if already one swap is done
                // if no swaps are done proceed
                if(unequalIndx != -1){ // if this is second mismatch
                    swap(s2[i],s2[unequalIndx]); // swap the 2
                    if(s1[i] == s2[i] && s1[unequalIndx] == s2[unequalIndx]){
                        // check if the current indx and prev mismatch are equal
                        // after swapping
                        // is yes mark count as 1
                        cnt = 1;
                        // mark mismatch indx as -1 (reset it)
                        unequalIndx = -1;
                    } else{
                        // if the swap indexes are unequal return false
                        return false;
                    }
                } else{
                    // if first mismatch mark it
                    unequalIndx = i;
                }
            }
        }
    
        // if no swaps are done
        // if unequal index is unresolved
        // the unequal strings
        if(unequalIndx != -1){
            return false;
        }
        
        return true;
    }
};
