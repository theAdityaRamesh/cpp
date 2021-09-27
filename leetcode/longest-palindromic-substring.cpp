//leetcode.com/problems/longest-palindromic-substring/

class Solution {
public:
    
    int checkFromCentre(const string& arr, int startIndx, int endIndx){
        
        if(arr == ""){return 0;}
        
        while(startIndx >= 0 && endIndx < arr.size() && arr[startIndx] == arr[endIndx]){
            startIndx--;
            endIndx++;
        }
        
        return endIndx - startIndx - 1;
    
    }
    
    
    string longestPalindrome(string s) {
        
        if(s == "" || s.size() == 1){
            string temp = "";
            temp += s[0];
            return temp;
        }
        
        int startIndx = 0;
        int endIndx = 0;
        int maxLen = 0;
        for(int i = 0; i < s.size(); i++){
            
            if(maxLen == s.size()){
                break;
            }
            
            int oddLenPal = checkFromCentre(s,i,i);
            int evenLenPal = checkFromCentre(s,i,i+1);
            int currLen = max(oddLenPal, evenLenPal);
                       
            if(currLen > maxLen){
                maxLen = currLen;
                startIndx = i -((currLen-1)/2);
                endIndx = i + ((currLen)/2);
            }
            
        }
        
        
        
        return s.substr(startIndx,maxLen);
        
    }
};
