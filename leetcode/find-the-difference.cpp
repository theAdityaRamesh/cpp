class Solution {
public:

        
    char findTheDifference(string s, string t) {
        
        
        int s1 = 0;
        // add the ascii values of the string1
        // sub the ascii values of the string2
        // the end sum will only have the extra added char
        for(int i = 0; i < s.size(); i++){
            s1 += int(s[i]);
            s1 -= int(t[i]);
        } s1 -= int(t.back());
        
        return char(-s1);
    }
    
    char findTheDifference(string s, string t) {
        
        if(s.empty()){
            return t[0];
        } 
        
        vector<int> alphabet(26,0);
        for(int i = 0; i < s.size(); i++){
            alphabet[s[i]-'a']++;
            alphabet[t[i]-'a']--;
        }
        
        alphabet[t.back()-'a']--;
        
        int cnt = 0;
        for(int i : alphabet){
            if(i<0){
                break;
            } cnt++;
        }
    
        return char('a'+cnt);
    }
};
