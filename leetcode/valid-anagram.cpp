class Solution {
public:
    bool isAnagram(string s, string anagram) {
        
        vector<int> alphabet(26,0);
        for(int c : s){
            alphabet[c-'a']++;
        } // count original string letter frequency
        
        for(int c : anagram){
            alphabet[c-'a']--;
        } // decrement from original frequecy
        // by comparing to anagram frequency
        
        for(int c : alphabet){
            if(c != 0){
                return false;
            } // if we have a letter not present in original string
        }// or if all letters of the original string are not used
        // we wont get 0 so we return false
        
        return true;
    
    }
};
