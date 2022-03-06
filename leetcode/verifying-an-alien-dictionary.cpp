class Solution {
public:
    
    
    bool inOrder(const vector<int>& alphabet, const string& curr, const string& next){
        
        // empty char is always the first in a dictionary
        if(curr == ""){
            return true;
        }
        
        // scan from left to right till the smaller string runs out
        for(int i = 0; i < min(curr.size(), next.size()); i++){
            // if we find a char which comes earlier in dictionary order
            // then its valid no need to check the others
            if(alphabet[curr[i]-'a'] < alphabet[next[i]-'a']){
                return true;
            // if we find a mismatch in the dictionary order
            // return false immediately no need to check the others
            } else if(alphabet[curr[i]-'a'] > alphabet[next[i]-'a']){
                return false;
            }
        }
        
        // if all chars are equal loop will end here
        // now if all chars are equal smaller words will come first
        // so if we have a larger word in the front
        // return false
        if(curr.size() > next.size()){
            return false;
        }
        
        // if all the above pass return true
        return true;
        
    }
    
    bool isAlienSorted(vector<string>& words, string order) {
        
        vector<int> alphabet(26,0);
        for(int i = 0 ; i < 26; i++){
            alphabet[order[i]-'a'] = i;
        } // alphabet has the order of words stored in it
        
        for(int i = 0; i < words.size()-1; i++){
            string curr = words[i];
            string next = words[i+1];
            // cpompare the words one at a time
            // in pairs
            if(!inOrder(alphabet, curr, next)){
                return false;
            }          
        }
        
        
        return true;
    }
};
