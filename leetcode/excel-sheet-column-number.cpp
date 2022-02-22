class Solution {
public:
    int titleToNumber(string columnTitle) {
        
        int res = 0;
        for(char c : columnTitle){
            res = res*26 + (c - 'A' + 1); // col num is in base 26 A -> 1 , AA -> 27
        }
        
        return res;
    }
};
