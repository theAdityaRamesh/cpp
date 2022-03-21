class Solution {
public:
        
    string removeDuplicateLetters(string s) {
        
        string ans = "";
        vector<int> indx(26,-1);
        // get last occurances of each 
        // alphabet in the string
        for(int i = 0; i < s.size(); i++){
            indx[s[i]-'a'] = i;
        }
        
        // in order to find the smallest substring
        // that is also the smallest ordered lexicographically
        // we need to keep the substring as much as possible in an
        // increasing order
        // so whenever we find a char that is smaller than ans.back()
        // we remove all the chars from the string till it reacheas a point
        // where we have a char at the back that is smaller than the curr char
        // during this operation we have to check for each char we remove 
        // if it occurs later in the string
        // if it does we can remove it now and take it back later
        // if not we cant remove it hence we stop
        // and append the curr char at the back
        
        stack<char> track;
        track.push(s[0]);
        vector<int> hashMap(26,0);
        hashMap[s[0]-'a'] = 1;
        
        for(int i = 1; i < s.size(); i++){
            if(hashMap[s[i]-'a'] != 1){
                while( !track.empty() && s[i] < track.top() && indx[track.top()-'a'] > i){
                    hashMap[track.top()-'a'] = 0;
                    track.pop();
                } 
                
                track.push(s[i]);
                hashMap[s[i]-'a'] = 1;  
            } 
        }
        
        // reverse the stack
        while(!track.empty()){
            ans = track.top()+ans;
            track.pop();
        }
        
        return ans;
    }
};
