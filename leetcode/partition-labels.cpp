class Solution {
public:
    vector<int> partitionLabels(string s) {
        
        // store last occurances of each alphabet
        vector<int> alphabet(26,-1);
        for(int i = 0; i < s.size(); i++){
            alphabet[s[i]-'a'] = i;
        }
        
        int nextIndx = alphabet[s[0]-'a'];
        int cnt = 0;
        
        // for each new alphabet added to the window
        // take the maximum possible last occurance among
        // them as all of the occurances have to be 
        // grouped together
        
        vector<int> ans;
        for(int i = 0; i < s.size(); i++){
            cnt = cnt + 1;
            nextIndx = max(nextIndx, alphabet[s[i]-'a']);
            if(i == nextIndx){
                ans.push_back(cnt);
                cnt = 0;
            }
        }
        
        return ans;
    }
};
