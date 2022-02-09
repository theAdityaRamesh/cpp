class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        
        int len = digits.size()-1;
        
       
        while(len >= 0 && digits[len] == 9 ){
            digits[len] = 0;
            len--;
        }  
                
        if(len == -1){
            digits.insert(digits.begin(),1);
        } else {
            digits[len] += 1;
        }
        
            return digits;
    }
};
