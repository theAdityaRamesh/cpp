class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        
        if(nums.size() == 1){
            return true;
        }
        
        
        bool trend = false;
        bool valid = false;
        
        for(int i = 1; i < nums.size(); i++){
            // skip the equal elements
            if(nums[i] == nums[i-1]){
                continue;
            }
            
            // if the trend is valid check it with current tredn
            if(valid & ((nums[i]>nums[i-1])!=trend)){
                return false;
            }
            
            // update the trend
            valid = true;
            trend = nums[i]>nums[i-1];
        }        
                
        return true;
    }
};
