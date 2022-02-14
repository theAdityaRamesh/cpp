// O(1) memory
// O(n) time

class Solution {
public:
       
    int returnIndx(char c){
        return int(c)-97; // helper function 
        // ascii of 'a' is 97
    }
    
    bool checkInclusion(string s1, string s2) {
        if(s1.length() > s2.length()) return false; // if second string is smaller it cant fit a permutation
        
        vector<int> track(26,0); // tracking array of len 26 for smallcase letter
        
        for(int i = 0;i < s1.size(); i++){
            track[returnIndx(s1[i])]++;
        } // count word freq in s1
        
        int start = 0;
        int size = s1.size();
        int end = start+size; // sliding window from start to end
        bool output = false;
        
        for(int i = 0; i < s2.size(); i++){ // scan from start to end of second string
            if( i == end){
                // if we reach end of sliding windoe
                output = true;
                for(int c : track){
                    if(c != 0){ // check if we have equal word frequency
                        output = false;
                        break; // if not break
                    }
                } if(output) return output;
                
                track[returnIndx(s2[end++])]--; // decrement word frequency of secind strnig
                track[returnIndx(s2[start++])]++; // increment the char in the prev sliding window
                
            } else {
                track[returnIndx(s2[i])]--; // if inside window decrease char frequency
            }
        }
        
        output = true; // if sliding windoe at end contains permutation loop will end
        for(int c : track){ // hence check once more
            if(c != 0){
                output = false;
                break;
            }
        } if(output) return output;
        
        return output;
    }
};

// O(1) memory
// O(n) time

class Solution {
public:
    
    int returnIndx(char c){
        return int(c) - 97;
    }
    
    bool checkInclusion(string s1, string s2) {
        
        vector<int> track(26, 0);
        int size = s1.size();
        
        for(int it =0; it < size;it++){
            track[returnIndx(s1[it])] += 1;
        }
        
        vector<int> trackCopy = track;
        int cnt = size;
        int start = 0;
        int end = start+size-1;
        
        for(int it = 0; it < s2.size(); it++){
            
             if( track[returnIndx(s2[it])] > 0 && it <= end){
                    cnt--;
                    track[returnIndx(s2[it])]--;
             } else if(cnt == 0 && it > end) {
                 return true;
             }  else {
                    it = start++;
                    cnt = size;
                    end = start+size-1;
                    track = trackCopy;
             }
            
        }
            return !bool(cnt);
    }
};
