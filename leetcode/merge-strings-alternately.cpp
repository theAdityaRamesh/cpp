class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        
        int size1 = word1.size();
        int size2 = word2.size();
        string ans = "";
        
        // scan thru both the strings
        for(int i = 0; i < size1+size2; i++ ){
            if(i<size1){ // if curr indx exists in str1
                ans += word1[i]; // append it
            }
            
            if(i<size2){ // same
                ans += word2[i];
            }
            
            // when curr indx DNE in one of the string only the other
            // one will run
        }
        
        return ans;
    }
};
