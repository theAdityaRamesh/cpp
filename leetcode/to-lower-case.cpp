class Solution {
public:
    string toLowerCase(string s) {
        // scan thru the string
        for(char& i : s){
            // if curr char is capital letter
            if(i >= 'A' && i <= 'Z'){
                // shift it by 'a'-'A' to make it small
                i = i+'a'-'A';
            }
        }
        
        return s;
    }
};
