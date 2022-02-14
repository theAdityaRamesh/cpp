class Solution {
public:  
    string reverseWords(string s) {
        
        vector<int> whiteSpaceIndx;
        int size = s.size();
        int left = 0;
        
        for(int it = 0; it < size; it++){ // scan for whitespace
            if(s[it] == ' '){ // if whitespace found
                reverse(s.begin()+left,s.begin()+it); // reverse from start pointer to whitespace-1
                left = it+1; // update start pointer to whitespace +1
            }
        }
        
        reverse(s.begin()+left, s.end()); // reverse last word after last whitespace till end
        
        return s;
        
    }
};
