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
        
        // we cam check all possible combinations of start and end
        // that would be brute force
        // but it would be O(nchoose2) or O(n^2)
        // a better way is to avoid doing that
        // and insetead check from the centre for each i
        // if the whole string is a palindrom we dont ahve to go
        // more than N/2
        // this is still however O(n^2)
        
        // another approach is to have a matrix of size NxN
        // we knoe that palindrom(i,j) is valid if palindrom(i-1,j-1) is valid and arr[i] == arr[j]
        // now we can start checking all possible pairs using 2 loops
        // and update max len if we find a larger palindrome
        
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
