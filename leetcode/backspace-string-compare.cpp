class Solution {
public:
    bool backspaceCompare(string s, string t) {
        
        // backspace operation is just like
        // removing chars from TOS
        // so maintain stack of chars
        // push the chars if its not a backspace
        // pop the chars if its a backspace
        // repeat for the other string
        // if we find a mismatch return false
        // both stacks shud be equal @ the end
        // we can use queue also or any DS that provides
        // insertion and deletion in o(1)
        
        
        stack<char> track;
        for(char c : s){
            if(c == '#'){
                if(!track.empty()){
                    track.pop();
                }
            } else{
                track.push(c);
            }
        }
        
        stack<char> track1;
        for(char c : t){
            if(c == '#'){
                if(!track1.empty()){
                    track1.pop();
                }
            } else{
                track1.push(c);
            }
        }
        
        if(track1.size() != track.size()){
            return false;
        }
        
        while(!track.empty()){
            if(track.top() != track1.top()){
                return false;
            }
            track.pop();
            track1.pop();
        }
        
        return true;
    }
};

class Solution1 {
public:
    bool backspaceCompare(string s, string t) {
        
        // backspace counts number of backspace 
        // encountered yet
        int backspace = 0;
        int sizeS = s.size();
        // charS counts number of chars left after
        // backspace
        int charS = sizeS;
        for(int i = sizeS-1; i >= 0; i--){
            if(s[i] == '#'){
                // if backspace char found
                s[i] = 'A';
                // replace with 'A'
                charS--;
                // reduce char left count
                backspace++;
                // increase backspace count
            } else if(backspace != 0){
                // if valid char found
                s[i] = 'A';
                // if backspace not zero
                backspace--;
                // reduce backspace
                charS--;
                // reduce char left count
            } 
        }
        
        // do the same for the other string as well
        backspace = 0;
        int sizeT = t.size();
        int charT = sizeT;
        for(int i = sizeT-1; i >= 0; i--){
            if(t[i] == '#'){
                t[i] = 'A';
                charT--;
                backspace++;
            } else if(backspace != 0){
                t[i] = 'A';
                backspace--;
                charT--;
            }
        }
        
        // if both string have 
        // diff number of chars left
        // return false
        if(charS != charT){
            return false;
        }
        
        // start scanning from back
        int si = sizeS-1;
        int st = sizeT-1;
        while(si >= 0 && st >= 0){
            // get the first valid char
            // ie char != A
            // in both strings
            while(si >= 0 && s[si] == 'A'){
                si -= 1;
            }
            while(st >= 0 && t[st] == 'A'){
                st -= 1;
            }
            
            // if we end up
            // out of space break
            if(si < 0 || st < 0){
                break;
            }
            
            // compare the valid chars
            if(s[si] != t[st]){
                // if not equal return false
                return false;
            }
            // go the prev char
            // as scannign backwarsds
            si--;
            st--;            
        }

        
        return true;
        
    }
};
