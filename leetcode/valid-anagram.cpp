// o(n) time
// o(1) space

class Solution {
public:
    
    int index(char c){
        return (c-'a');
    }
    
    vector<int> findAnagrams(string s, string p) {
        
        int sizeS = s.size(); // size of s string
        int sizeP = p.size(); // size of og string
        
        if(sizeS < sizeP){
            return {}; // if the search string is smaller
        } // no anagrams are possible
        
        vector<int> res; // result vector
        vector<int> alphabet(26,0); // alphabet vector
        // for counting the frequency of the og string
        
        for(int i : p){
            alphabet[i-'a']++; // count the frequency of each letter
        }
        
        int start = 0; // start of sliding window
        int len = sizeP; // len of remaining vars
        // we use variable len to detect outliers
        
        // scan from first to last index
        for(int i = 0; i < sizeS; i++){   
            
            if(alphabet[s[i]-'a'] > 0){
                // if the current element is >0 frequency
                // since we are decrementing the frequency in each iteration
                // since only the og string letters have freq >=1 
                // all the other letters will have either zero or -ve frequency
                // so if current letter is having >0 frequncy reduce the length of the remaining chars
                len--;
            } else{
                // otherwise if current is a outlier
                // increase len as it shud not be present in the sliding window
                len++;
            }
            
            // reduce frequency of the current letter
            alphabet[s[i]-'a']--;
            
            // if the len becomes zero it means all the letters in the current window
            // are valid and without overflow
            // hence its a valid anagram
            // hence push the start index
            if(len == 0){
                res.push_back(start);
            }
            
            // after the sizeP-1 index every time we wikk
            // have to move the window
            if(i >= sizeP-1){
                // now start is shifted forward
                // so that letter is out of the window now
                // so increase its frequency
                alphabet[s[start]-'a']++;
                // here we check if its > 0
                // if its a valid char it will have >0
                // if its not in overflow
                // ie many copies have been found in the window
                // so its not forming a valid anagram
                if(alphabet[s[start]-'a'] > 0){
                    len++; // increase the len as we have removed a valid char
                } else{
                    len--; // otherwise decrease the len as we have 
                    // either reduced overflow
                    // or removed an outlier
                } start++; // shift start forward
            }   
        }   
        return res;
        // return the ans
            
        }
        
        
};

// o(n^2) solution
// basically checking 
// all the sliding window
// using 2 loops
// and after eachiong window
// doing a reset
// no memeory

class Solution {
public:
    
    int index(char c){
        return (c-'a');
    }
    
    vector<int> findAnagrams(string s, string p) {
        
        int sizeS = s.size();
        int sizeP = p.size();
        
        if(sizeS < sizeP){
            return {};
        }
        
        vector<int> res;
        int start = 0;
        vector<int> alphabet(26,0);
        
        for(int i : p){
            alphabet[i-'a']++;
        }
        
        int i = 0;
        while(i < (sizeS-sizeP+1)){
            if( alphabet[index(s[i])] > 0 ){
               
                start = i;
                vector<int> anagram = alphabet;
                bool good = true;
                while(start < sizeS && start <= (i + sizeP - 1)){
                    if(--anagram[index(s[start])] < 0){
                        good = false;
                        break;
                    } start++;
                }
                if(good && start == (i+sizeP) ){res.push_back(i);}
            }
            
            i++;
            while(i < sizeS && alphabet[index(s[i])] == 0){
                i++;
            };
        }
        
        return res;
    }
};
