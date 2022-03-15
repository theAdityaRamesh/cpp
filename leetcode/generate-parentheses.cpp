// using catalan numbers
class Solution {
public:    
    vector<string> generateParenthesis(int n) {
        
        // vector of ans
        vector<vector<string>> ans;
        ans.push_back({""}); // n = 0
        ans.push_back({"()"}); // n = 1
        
        // generate the catalan numbers
        // start with 1 pair () then add the rest inside or outside
        // to form the rest of the combinations
        // for n = 4
        // (0)3
        // (1)2
        // (2)1
        // (3)0
        // ... just generate the nth catalan numbers
        // save the previous states to avoid recomputation
        
        int i = 2;
        while(i <= n){
            int in = 0;   
            int out = i-1;
            vector<string> curr;
            while(in < i){
                for(int i = 0; i < ans[in].size(); i++){
                    for(int j = 0; j < ans[out].size(); j++){
                        curr.push_back('('+ans[in][i]+')'+ans[out][j]);
                    }
                }
                in++;
                out--;
            }
            ans.push_back(curr);
            ++i;            
        }        
        
        return ans.back();
    }
};
/// ----------------------------------------------------------------------------------------------------------------------------------------------------------------
class Solution {
public:
    
    void fill(vector<vector<string>>& ans, int i, int n){
        
        if(i <= n){
            set<string> curr; // maintain a set
            
            // in each iteration
            // as we add one more pair of parenthesis
            // we can use the prev generated pairs 
            // and combine them
            // eg for 6
            // 1 + 5
            // 2 + 4
            // 3 + 3
            // no need to do further as it will repeat then
            // the set keeps the duplicates from occuring
            
            // 1 + i-1
            // i = 2 ans[0]
            // i = 3 ans[1] ..
            for(string s : ans[i-2]){
                curr.insert("()"+s);
                curr.insert(s+"()");
                curr.insert('('+s+')');
            }
            
            if(i > 3){
                int start = 1; // 2 
                int end = i-3; // i-2
                // i = 4 start = 1 end = 1
                // i = 5 start = 1 end = 2
                // i = 6 start = 1 end = 3
                while(start <= end){
                    for(string endS : ans[end]){
                        for(string startS : ans[start]){
                            curr.insert(endS+startS);
                            curr.insert(startS+endS);
                        }
                    }
                    
                    start++;
                    end--;
                }
            }
            // at the end of each iteration 
            // add the current to a vector and store it 
            
            vector<string> temp(curr.begin(), curr.end());
            ans.push_back(temp);
            fill(ans, ++i, n);   
        }        
    }
    
    vector<string> generateParenthesis(int n) {
        
        vector<vector<string>> ans;
        ans.push_back({"()"});
        fill(ans,2 ,n);
        return ans.back();
    }
};
