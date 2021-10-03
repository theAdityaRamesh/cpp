//leetcode.com/problems/longest-common-prefix/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
     
        
        string LCP = strs[0];
        int it = 1;
        while(it < strs.size()){
            
            if(strs[it][0] != LCP[0] || LCP == ""){
                return "";
            }
            
            for(int i = LCP.size()-1; i > 0; i--){
                if(strs[it][i] != LCP[i]){
                    LCP.erase(i);
                } 
            }
            
            it++;
        }
        return LCP;
    }
};
