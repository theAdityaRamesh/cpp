class Solution {
public:
    string interpret(string command) {
        
        int size = command.size();
        string ans = "";
        
        for(int i = 0; i < size; i++){
            // use if cond to check the curr and next
            // and move the pointer forwarda
            if(command[i] == '('){
                if(command[i+1] == 'a'){
                    ans += "al";
                    i += 2;
                } else{
                    ans += "o";
                    i++;
                } 
            } else if(command[i] == 'G'){
                ans += "G";
            }
        }
        
        return ans;
    }
};
