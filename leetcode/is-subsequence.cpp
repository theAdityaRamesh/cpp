class Solution {
public:
    bool isSubsequence(string s, string t) {
        
        int sizeS = s.size();
        int sizeT = t.size();
        
        if(sizeS == 0){
            return true;
        } 
        
       
        int ptr = 0;
        // start from start of the t string
        // whose chars have to be deleted
        for(int i = 0; i < sizeT; i++){
            if(t[i] == s[ptr]){
                // if we find a match 
                // move the match ptr in s string
                // forward
                ptr++;
            }
            
            // if we reach end of s string
            // it means its a subsequence
            if(ptr == sizeS){
                return true;
            }
        }
        
        // for subsequence who are not in order
        //ex : s = aec t = absbce
        // the pointer will never reach the end 
        // hence we reutnr false here
        
        
        return false;
        
    }
};
