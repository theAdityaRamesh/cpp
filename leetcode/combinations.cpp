// recursive implementation

class Solution {
public:
    
    void combine(int n, int k, int p1, vector<int> ans, vector<vector<int>>& res){
        
        if( k == 1){
            ans.push_back(p1);
            res.push_back(ans);
        }
        
        if( k > 0){
            ans.push_back(p1);
            for(int i = p1+1; i <= n; i++){
                combine(n, k-1, i, ans, res);
            } 
        } 
            
    }
 
    vector<vector<int>> combine(int n, int k) {

        // return n choose k
        vector<vector<int>> res;
        
        for(int i = 1 ; i <= n-k+1; i++){
            vector<int> ans;
            combine(n, k, i, ans, res);
        }

        return res;
    }
};
