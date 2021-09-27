// https://leetcode.com/problems/letter-combinations-of-a-phone-number/

class Solution {
public:
    
    vector<string> phoneMap = 
        {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    
    void generateCombinations(int digits, vector<string>& result, string comb) {
        
        if(digits == 0){
            result.push_back(comb);
            return;
        } else {
            // loop thru pssiblities of next digit
            string current = phoneMap[digits%10 - 2];
            for(string::iterator it = current.begin(); it < current.end(); it++){
                generateCombinations(digits/10, result, comb+(*it));        
            }
        }
    }
    
    
    vector<string> letterCombinations(string digits) {
         
        vector<string> emp; 
        if(digits.empty()) {return emp; }
        string comb = "";
        reverse(digits.begin(),digits.end());
        generateCombinations(stoi(digits), emp, comb );
        
        
        return emp;
    }
};
