class Solution {
public:
    string freqAlphabets(string s) {
        string ans = "";
        // scan from left to right
        for(int i = 0; i < s.size(); i++){
            // check the next to next char for #
            if(i+2 < s.size() && s[i+2] == '#'){
                // sub '1'*10 from tens place and '0' from units place to scale to 0
                // then add 'j'
                ans += char(s[i]*10 + s[i+1] -'0'-'1'*10+'j');
                i+=2;
            } else {
                // scale '1'->'9' to zero by sub '1'
                // then add 'a'
                ans += char(s[i]-'1'+'a');
            }
        }
        
        return ans;
    }
};
