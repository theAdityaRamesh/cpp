// O(1) memory
// O(n^2) time

class Solution {
public:
    
    int returnIndx(char c){
        return int(c) - 97; // total 26 asicii chars // a has ascii 97
    }
    
    bool checkInclusion(string s1, string s2) {
        
        vector<int> track(26, 0);
        int size = s1.size();
        
        for(int it =0; it < size;it++){
            track[returnIndx(s1[it])] += 1; // upadte number of occurances of each char in the vector array
        }
        
        vector<int> trackCopy = track;
        int cnt = size; // cnt = size of permutation
        int start = 0; // start is start of sliding window
        
        for(int it = 0; it < s2.size(); it++){
            
            if( it == (start+size-1) ){
                if (cnt == 0){ // if we reach end of sliding window check count value 
                    return true; // if count value is zero return true
                } else {
                    it = start++; // reset the loop iterator // increment start of sliding window
                    cnt = size; // reset the count variable
                    trackCopy = track; // reset the tracking array
                }
            } 
            
            if( trackCopy[returnIndx(s2[it])] != 0){ // if we get a match
                trackCopy[returnIndx(s2[it])]--; // if we get a match reduce number of occurances
                cnt--; // reduce cnt 
            } 
            
        }
            return !bool(cnt);
    }
};
