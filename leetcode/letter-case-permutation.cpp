class Solution {
public:
    
    void invert(char& c){
        // helper function to convert from
        // a -> A
        // A -> a
        if(c < 'a'){ // capital
            c = char(c+'a'-'A');
        } else { // small
            c = char(c+'A'-'a');
        }
        
    }
    
    void letterCasePermute(vector<string>& res, string s,int i){
        
        res.push_back(s); // push back current permutation
        
        if(i > s.size()-1){
            return; // if we go out of bounds return
        }
        
        // permute from current position
        // invert current position
        // call function with current pos inverted
          // on each call the current permutation 
          // is saved at top
        // re-invert to restore same string
        for(int j = i; j < s.size(); j++ ){
            if(s[j] > '9'){ // if its not digit
                invert(s[j]);
                letterCasePermute(res, s, j+1);
                invert(s[j]);
            }
        }
    }
    
    vector<string> letterCasePermutation(string s) {
        
        vector<string> res;
        letterCasePermute(res, s, 0);      
        return res;
    }
};
