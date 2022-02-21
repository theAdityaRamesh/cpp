class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        
        if(nums.size() == 1){
            return nums[0];
        } // if one element then return that
        
        if(nums.size() == 2){
            if(nums[0] + 1 == nums[1]){
                // if related two elements
                // return max of the two
                return max(nums[0], nums[1]);
            } else{
                // if unrelated return sum of the two
                return nums[0] + nums[1];
            }
        }
        
        
        vector<pair<int,int>> pts;
        // sort the original array
        sort(nums.begin(), nums.end());
        
        // calculate total number of occurances and 
        // store the sum as <number,pts>
        int curr = nums[0];
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] == nums[i-1]){
                curr += nums[i];
            } else{
                pts.push_back(make_pair(nums[i-1], curr));
                curr = nums[i];
            }
        } pts.push_back({nums.back(), curr});

        
        if(pts[1].first - 1 == pts[0].first){
            // if first 2 are related
            // we will delete max of the 2
            pts[1].second = max(pts[1].second, pts[0].second);   
        } else{
            // if unrelated we will delete
            // both
            pts[1].second += pts[0].second;
        }
        
        // scan from i = 2 3rd index
        for(int i = 2; i < pts.size(); i++){
            // get current points and number
            int currNum = pts[i].first;
            int currPts = pts[i].second;
        
            // if current number is related to prev number
            if(currNum - 1 == pts[i-1].first){
                // since we cant delete adjacent
                // get prev of adjacent
                // calculate sum with curr points
                currPts += pts[i-2].second;
                if(currPts > pts[i-1].second){
                    // if we gain more points 
                    // compared to deleting the adjacent
                    // update the current with current points
                    pts[i].second = currPts;
                } else {
                    // otherwise if current points are less than 
                    // prev obtained points
                    // update the current index with max points
                    // possible to be gained till index i-1
                    pts[i].second = pts[i-1].second;
                }
            } else {
                pts[i].second += pts[i-1].second;
                // if unrelated add the prev max points
            }            
        }
        
        //return the max points
        return pts.back().second;
    }
};

