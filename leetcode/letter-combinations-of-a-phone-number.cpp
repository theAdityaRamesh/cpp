// https://leetcode.com/problems/letter-combinations-of-a-phone-number/

class Solution {
public:
    
    
    
    void generateCombinations(int digits, vector<string>& result, string comb) {
        
        if(digits == 0){
            result.push_back(comb);
            return;
        } else {
            // loop thru pssiblities of next digit
            string current = phoneMap[digits%10 - 2];
            for(string::iterator it = current.begin(); it < current.end(); it++){
                generateCombinations(digits/10, result, (*it)+comb);        
            }
        }
    }
    
    
    vector<string> letterCombinations(string digits) {
         
        vector<string> emp; // string of ans
        if(digits.empty()) {return emp; }
        string comb = "";
        
        // convert the digit to integer
        // so that we can acess the phoneMap
        // iterate the string backwards
        // and multiply by placevalue
        int digit = 0;
        int placeVal = 1;
        for(string::reverse_iterator c = digits.rbegin(); c != digits.rend(); c++){
            digit += (*c-'0')*placeVal;
            placeVal *= 10;
        }
        
        // call the generator fun recursively
        // generate the strings recursively
        // basically there will be k loops
        // k is num of digits
        // so we'll use recursion to implement k loops
        generateCombinations(digit, emp, comb );
        
        
        return emp;
    }
    
private:
    vector<string> phoneMap = 
        {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    
};
