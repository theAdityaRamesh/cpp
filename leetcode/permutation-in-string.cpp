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
