class Solution {
public:
    int lengthOfLastWord(string s) {
        
        // remove whitespaces @ the end
        int ptr = s.size()-1;
        while(ptr >= 0 && s[ptr] == ' '){
            ptr--;
        }
        int start = ptr; // ptr @ last letter of last word
        
        // move it back till we find another space or we reach the 
        // start of string
        while(ptr >= 0 && s[ptr] != ' '){
            ptr--;
        }
        
        // return the distance b/w start and ptr
        return start-ptr;
    }
};
