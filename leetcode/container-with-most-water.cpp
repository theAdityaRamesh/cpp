class Solution {
public:
    
    int maxArea(vector<int>& nums) {
        
        
        int left = 0; // mark left pointer
        int size = nums.size(); // getSize
        int right = size-1; // mark right pointer
        int width = size-1; // width will be total bars - 1
        int water = min(nums[left], nums[right])*width; // intitial water held is
        // we take min of both the heights beacause
        // if we fill more water than the min height
        // it will spill over
        
        while(left < right){
            // before each iteration check the max water hedl
            water = max(water, min(nums[left], nums[right])*width);
            // if left wall is taller
            // move inwards in hope of finding a taller right wall
            if(nums[left] > nums[right]){
                right--;
            } else {
                // else
                // move left forward in hope of finding a taller left wall
                // to match the right wall
                left++;
            }
            
            // since we are moving inwards
            // we decrease the width 
            width--;
        }
        
        return water;
        
    }
};
