class Solution {
public:
    
    void check(vector<vector<int>>& ans, const vector<int>& arr, vector<int>& curr, int indx, int target ){
        
        if(target == 0){
            ans.push_back(curr);
            return;
        }
        
        for(int i = indx+1; i < arr.size(); i++){
            if( target-arr[i] >= 0){
                
                if(i > indx+1 && arr[i] == arr[i-1]){
                    continue;
                }
                // just allow the duplicate value to choose the duplicates
                // and skip the rest
                curr.push_back(arr[i]);
                check(ans, arr, curr, i, target-arr[i]);
                curr.pop_back();
                
            }
        }
    }
    
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());

        // if min element > target 
        // no possible ans
        if(candidates[0] > target){
            return {};
        } 
        
        // same logic as combinations 1
        // we take consecutively gretear elements and
        // check if we can reach the target
        // otherwise abandon it if it gets gretear then the target
        vector<vector<int>> ans;
        vector<int> curr;
        for(int i = 0; i < candidates.size(); i++){
            if(candidates[i] <= target){
                
                // to avoid duplicates
                // only allow the number with the same value as duplicate to
                // choose it and skip the rest of the duplicates
                // this way we will have combinations with all the duplicates
                // and avoid the duplicate combination caused by starting with
                // the duplicates
                if(i > 0 && candidates[i] == candidates[i-1]){
                    continue;
                }
                curr.push_back(candidates[i]);
                check(ans, candidates, curr, i, target-candidates[i]);
                curr.pop_back();
            }
        }
        
        
        return ans;
    }
};
