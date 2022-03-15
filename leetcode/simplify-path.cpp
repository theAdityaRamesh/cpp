class Solution {
public:
    string simplifyPath(string path) {
        // O(N) time O(N) space
        // solution using stack
        // push the folder names into stack
        // each folder name is sepearated by a /
        // if we encounter /.. or /. commands 
        // remove elements from the stack
        
        stack<string> track;
        string folder_name = "";
        
        for(int i = 0; i < path.size(); i++){
            if(path[i] != '/'){
                folder_name = "";
                // if we encounter a /
                // get everything till the next / or END
                while(i < path.size() && path[i] != '/' ){
                    folder_name += path[i];
                    i++;
                }
                
                // if we get a name ..
                // it means go back so pop the top element
                if(folder_name == ".."){
                    if(!track.empty()){
                        track.pop();
                    }
                // if we get a current directory cmd
                // ignore dont do anything
                } else if(folder_name == "."){
                    continue;
                // otherwise push the valud folder name 
                } else{
                    track.push('/'+folder_name);
                }
            }
        }
        
        // get all the elements from the stack
        string ans = "";
        while(!track.empty()){
            ans = track.top()+ans;
            track.pop();
        }
        
        // if we are @ root dir
        // return /
        if(ans.empty()){
            return "/";
        }
        
        return ans;
    }
};
// O(n^2) time
// bacause in worst case for i/p like this /../../../../../..
// we have to scan till the start every time 
// to find the prev directory
// o(1) space
class Solution {
public:
    string simplifyPath(string s) {
        
        // if path just contains /
        // no point in checking
        if(s.size()==1){
            return s;
        }
        
        // mark the prev char
        char prev = s[0];
        // iterate thru the entire string
        for(int i = 1; i < s.size(); i++){
            
            // use ; to mark as invalid
            if(s[i] == ';'){
                continue;
            }
            
            // if prev is not assigned 
            // assign the current value as prev
            if(prev == ' '){
                prev = s[i];
            }
            
            // if we have a /. combination
            if(s[i] == '.' && s[i-1] == '/'){
                // ignore if we have something likse /....
                // since its treated as a filename
                if(i+2 < s.size() && (s[i+2] == '.' || s[i+2] > '/' ) && s[i+1] == '.'){
                   i = i+2; // skip the dots
                    prev = ' '; // mark prev as unassigned
                   continue;
                }
                
                // if we have a /.. combination
                if(i+1 < s.size() && s[i+1] == '.'){
                        // mark the /.. as invalid with ;
                        s[i] = ';';
                        s[i+1] = ';';
                        s[i-1] = ';';
                        // start checking back
                        // till we reach the START or
                        // the prev /
                        // since we have to move back one step
                        int j = i-2;
                        while(j >= 0 && s[j] != '/'){
                            s[j] = ';';
                            j--;
                        } if(j >= 0){s[j] = ';';}
                        prev = ' ';
                } else {
                    // ignore the actual directories
                    if(i+1 < s.size() && s[i+1] > '/'){
                        continue;
                    }
                    // handle the current directory case
                    // /.
                    s[i] = ';';
                    s[i-1] = ';';
                    prev = ' ';
                }
              // handle the multiple //// case  
            } else if(s[i] == '/' && i-1 >= 0 && s[i-1] == '/'){
                s[i-1] = ';';
            }            
        }
        
        // ignore all the chars marked with ;
        // append the rest to a new string
        // and return it
        string ans = "";
        for(char c : s){
            if(c != ';'){
                ans += c;
            }
        }
        
        if(ans.empty()){
            return "/";
        }
        
        if(ans.size() > 1 && ans.back() == '/'){
            ans.erase(ans.size()-1,1);
        }
        
        
        return ans;
    }
};
