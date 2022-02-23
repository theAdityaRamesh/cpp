class Solution {
public:
    int firstUniqChar(string s) {
        
        vector<int> lowerCase(26,0);
        
        for(int c : s){
            lowerCase[c-'a']++;
        } // count the letter frequency
        
        int indx = 0;
        for(int c : s){
            if(lowerCase[c-'a'] == 1){
                return indx;
            } indx++;
        } // return the first letter with freq one
        
        // if none found return -1
        return -1;
    }
};
