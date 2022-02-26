class Solution {
public:
    
    bool notPair(char c1, char c2){
        // checks for matching bracket pairs
        // returns true if not matching
        if(c1 == '(' && c2 != ')'){
            return true;
        } else if(c1 == '{' && c2 != '}'){
            return true;
        } else if(c1 == '[' && c2 != ']'){
            return true;
        } else {
            return false;
        }
    }
    
    bool isValid(string s) {

        int size = s.size();
        
        // if empty then always true
        if(size == 0){
            return true;
        }
        
        // single paranthesis cant
        // be matching
        if(size == 1){
            return false;
        }
        
        // odd length cant be matching
        if(size%2){
            return false;
        }
        
        // if @ front or back we have closing or opening then also its not possible
        if(s[0] == '}' || s[0] == ')'  || s[0] == ']'|| s.back() == '(' || s.back() == '{' || s.back() == '['){
            return false;
        }
        
        // if all of the above is false
        // maintain stack of opening paranthesis
        stack<char> check;
        for(int i = 0; i < size; i++){           
            if(s[i] == '[' || s[i] == '{' || s[i] == '('){
                check.push(s[i]); // push opening paranthesis into stack
            } else {
                // if closing paraenthesis found
                // if stack empty
                // or if most recently encountered opening bracket
                // does not form a pair
                // return false
                if(check.empty() || notPair(check.top(), s[i])){
                    return false;
                } check.pop(); // remove it as it has been validated
            }
        }
        
        // if at the end some opening have
        // not been validated
        // return false
        if(!check.empty()){
            return false;
        }
        
        return true;
    }
};
