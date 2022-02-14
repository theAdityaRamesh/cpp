//leetcode.com/problems/longest-substring-without-repeating-characters/

class Solution {
public:
    
    int indx(const char& c){
        return int(c) - 32; // convert char to int from ascii table
    }
    
    int lengthOfLongestSubstring(string s) {
        int maxLen = 0;
        int currLen = 0;
        vector<int> track(95,-1); // all digits, spaces and capital and small letters sum to 95
        int start = 0;
        
        for (int it = 0; it < s.size(); it++){
            
            int index = indx(s[it]);// if match found
            if ( track[index] == -1 || track[index] < start ){ // check for repitions by comparing start index and last occurance 
                track[index] = it; // upadte last found index // if last occurance < start it means char was not present in current string
                
            } else {
                start = track[index] + 1;
                track[index] = it; // if match found then updaate max len
                                    // restart the tracking
                maxLen = maxLen < currLen ? currLen : maxLen;                

            }
            currLen = it - start+1;
        }
        
        maxLen = maxLen < currLen ? currLen : maxLen;
        return maxLen;
        
               
    }
};
