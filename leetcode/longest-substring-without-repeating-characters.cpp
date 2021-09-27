//leetcode.com/problems/longest-substring-without-repeating-characters/

class Solution {
public:
    
    int indx(const char& c){
        return int(c) - 32;
    }
    
    int lengthOfLongestSubstring(string s) {
        int maxLen = 0;
        int currLen = 0;
        vector<int> track(95,-1);
        int start = 0;
        
        for (int it = 0; it < s.size(); it++){
            
            int index = indx(s[it]);
            if ( track[index] == -1 || track[index] < start ){
                track[index] = it;
                
            } else {
                start = track[index] + 1;
                track[index] = it;
                
                maxLen = maxLen < currLen ? currLen : maxLen;                

            }
            currLen = it - start+1;
        }
        
        maxLen = maxLen < currLen ? currLen : maxLen;
        return maxLen;
        
               
    }
};
