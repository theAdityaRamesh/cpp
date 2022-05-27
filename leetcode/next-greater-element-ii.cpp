class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        
        
        // vector to track encounterd elements
        vector<int> track_indx;
        // we mark first as encountered
        track_indx.push_back(0);
        // ans vector
        vector<int> ans(nums.size(), -1);
       
        // move from second to last element
        for(int i = 1; i < nums.size(); i++){
            // if we find an element greatear than the last encountered
            // remove elements till this is true
            // the ans for all these elemetns is the current element
            while( !track_indx.empty() && nums[track_indx.back()] < nums[i]){
                ans[track_indx.back()] = nums[i];
                track_indx.pop_back();
            } track_indx.push_back(i); // push the curr element
        } // check ans for curr elemetn in the next elements
        
        // last encountered element which has not yet found
        // a next greatear
        // since its circular after the last element start
        // from the start
        int curr_last = track_indx.back();
        for(int i = 0; i < curr_last; i++){
            while(!track_indx.empty() && nums[i] > nums[track_indx.back()]){
                ans[track_indx.back()] = nums[i];
                track_indx.pop_back();
            } // do the same thing as the first pass
        } // but dont store the elements as they have already been encountered
        
        // at end of 2nd pass elements left in vector have no next greatear element
       
        
        return ans;
    }
};
