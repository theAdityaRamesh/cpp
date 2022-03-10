class Solution {
public:
    
    void check(vector<vector<int>>& ans, const vector<int>& arr, vector<int>& curr, int indx, int target ){
        
        // at each call we first check if we have reached the target
        if(target == 0){
            // if yes save the ans 
            ans.push_back(curr);
            // return
            return;
        }
        // otherwise
        // since each element can be used multiple times
        // start with the current element 
        // scan to the right where elements >= curr
        for(int i = indx; i < arr.size(); i++){
            // if the curr sum + the new element is < target
            if( target-arr[i] >= 0){
                // we push it and check further in the next calls
                curr.push_back(arr[i]);
                check(ans, arr, curr, i, target-arr[i]);
                // remove the prev element because we need to check a new 
                // combination
                curr.pop_back();
            }
            
            // if its greatear than target do nothing
            // it will return to the prev call
            // and get removed from the curr vector
        }
    }
    
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());

        // if min element > target 
        // no possible ans
        if(candidates[0] > target){
            return {};
        } 
        
        // create vector to store ans
        vector<vector<int>> ans;
        // curr vector
        vector<int> curr;
        // recursively check
        check(ans, candidates, curr, 0, target);
        
        return ans;
    }
};
