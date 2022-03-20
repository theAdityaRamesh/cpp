class Solution {
public:
    int scoreOfParentheses(string s) {
        
        // () -> score of 1
        // (inside) -> score_inside * 2
        // (a)(b) -> a+b
        // so bascially
        // the only way to increase score is by 
        // doing ()()
        // otherwise we double the ans
        
        int ans = 0;
        stack<int> save ;
        for(int i = 0; i < s.size(); i++){
            
            // if we have ()
            // add it to the TOS because we are inside
            // TOS
            if(s[i] == '(' && s[i+1] == ')'){
               if(!save.empty()){
                   save.top()++;
               } else{
                   // otherwise 
                   // if we have no TOS
                   // ie we are not inside a bracket
                   // add it directly to the ans
                   ans++;
               }
               i++;
           } else if(s[i] == '('){
               // if we find an opening bracket
               // that is not ()
                // mark it by pushing to stack
                // we are now (inside) so we will
                // mark the opening
               save.push(0);
           } else{
                // if we reach end of (inside)
                // double the curr value
                // store it in prev TOS
                // if we are done with the brackets
                // ie there is no TOS
                // the store it in the ans 
               int temp = save.top()*2;
               save.pop();
               if(!save.empty()){
                   save.top() += temp;
               } else{
                   ans += temp;
               }
               
           }
        }
        
        return ans;
    }
};
