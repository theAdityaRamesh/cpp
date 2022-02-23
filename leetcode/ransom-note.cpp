class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        
        vector<int> alphabet(26,0);
        
        for(int c : magazine){
            alphabet[c-'a']++;
        } // count the orignial letter frequency
        
        for(int c : ransomNote){
            alphabet[c-'a']--;
            if(alphabet[c-'a'] < 0){
                return false;
            }// if additional letters used
        }// or letter which is not used in the magazine
        // is used then return faslse
        
        return true;
    }
};
