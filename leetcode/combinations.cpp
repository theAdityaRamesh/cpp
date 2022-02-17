// iterative solution 

class Solution {
public:

    vector<vector<int>> combine(int n, int k) {

        // return n choose k
        vector<vector<int>> res;
        vector<int> ans(k, 0);
        int indx = 0;
//         0 0 0 
//         1 0 0 
//         1 1 0
//         1 2 2
//         1 2 3 -> push back i = 2
//         1 2 4
//         1 2 5 
//         1 2 6 -> i--, 6 > n-k+i+1
//         1 3 3 
//         1 3 4 -> push back i = 2
        
        while( indx >= 0){            
            ans[indx]++;
            
            if( ans[indx] > n-k+indx+1){
                indx -= 1;
            } else if(indx == k-1){
                res.push_back(ans);
            } else{
                indx += 1;
                ans[indx] = ans[indx-1];
            }
            
        }
        return res;
    }
};

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
