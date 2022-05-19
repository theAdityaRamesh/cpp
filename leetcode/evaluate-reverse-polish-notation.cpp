class Solution {
public:   
    
    int evalRPN(vector<string>& tokens){
        
        // for RPN we have number number token
        // we use stack to evalueate the result
        // first way is to go back to front
        // if we hit a operator we need the operands
        // for that we have to solve the previous operations 
        // if any otherwise we return the number as it is

        
        int indx = tokens.size()-1;
        return solve(tokens, indx);
    }
        
    int evalRPN1(vector<string>& tokens) {
        
        // 2nd way is to move front to back
        // we keep pushing the numbers into a stack
        // until we hit a operator
        // then we take the top 2 numbers 
        // operate on it
        // and push it back
        // the result is the operand for some other operation
        // when all tokens have been parsed
        // return TOS.
        
        stack<string> RPN;
        
        for(string c : tokens){
            if(c == "+"|| c == "-" || c == "*" || c == "/"){
                int op1 = stoi(RPN.top());
                RPN.pop();
                int op2 = stoi(RPN.top());
                RPN.pop();
                RPN.push(to_string(operate(op2,op1, c)));
            } else{
                RPN.push((c));
            }
        }
        
        return stoi(RPN.top());
    }
    
private:
        int operate(int o1, int o2, string c){
        
        int ans = 0;
        
        if(c == "+"){
            ans = o1+o2;
        } else if(c == "-"){
            ans = o1-o2;
        } else if(c == "*"){
            ans = o1*o2;
        } else if(c == "/"){
            ans = o1/o2;
        }
        return ans;
    }
    
    int solve(const vector<string>& tokens, int& indx){
        
        if(tokens[indx] == "+"){

            indx -= 1; // decrement the index so that we go the next opetation or number
            // we first get operand 2
            int op2 = solve(tokens,indx);
            // then get operand 1
            int op1 = solve(tokens,indx);
            // return the ans
            return op1+op2;
        } else if(tokens[indx] == "-"){
            indx -= 1;
            int op2 = solve(tokens, indx);
            int op1 = solve(tokens, indx);
            return op1-op2;
        } else if(tokens[indx] == "*"){
            indx -= 1;
            int op2 = solve(tokens, indx);
            int op1 = solve(tokens, indx);
            return op1*op2;
        } else if(tokens[indx] == "/"){
            indx -= 1;
            int op2 = solve(tokens, indx);
            int op1 = solve(tokens, indx);
            return op1/op2;
        } else{
            // we have hit a number
            // so we return the number
            // and post decrement the indx
            // to go to the next operation.
            return stoi(tokens[indx--]);
        }
        
    }
    
};
