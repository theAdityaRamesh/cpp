class Solution {
public:
    string minRemoveToMakeValid(string s) {
        
        // use a stack and check for validity of brackets
        stack<int> track;
        for(int i = 0; i < s.size(); i++){
            // push all opening brackets
            if(s[i] == '('){
                track.push(i);
            } else if(s[i] == ')'){
                // if we find a closing bracket 
                // with no opening bracket
                // mark as A
                if(track.empty()){
                    s[i] = 'A';
                } else if(s[track.top()] == '('){
                    track.pop();
                }
            }
            
        }
        
        // after passing the entire string
        // all opening brackets 
        // that have no closing brackets will be left
        // mark them as A
        while(!track.empty()){
            s[track.top()] = 'A';
            track.pop();
        }
        
        // take all except the A's
        string ans = "";
        for(char c : s){
            if(c != 'A'){
                ans += c;
            }
        }
        
        return ans;
    }
};
