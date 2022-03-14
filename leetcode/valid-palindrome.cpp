class Solution {
public:
    bool isPalindrome(string s) {
        
        string new_s = "";
        for(char c : s){
            // if c is uppercase
            // convert to lower case
            if(c >= 'A' && c <= 'Z'){
                c = c+'a'-'A';
            }
            // if c is alpha numeric
            // append to new string
            if((c >= '0' && c <='9') || (c >= 'a' && c <= 'z')){
                new_s += c;
            }
        }
        
        // expand from centre
        // and check if palindrome
        int left = new_s.size()/2-!(new_s.size()&1);
        int right = new_s.size()/2;
        while(left >= 0 && right <= new_s.size()-1){
            if(new_s[left] != new_s[right]){
                return false;
            }
            left--;
            right++;
        }
        
        // if both pointers have covered entire string
        // then its a palindrom
        // otherwise the code would have terminated in the loop
        return true;
    }
};
