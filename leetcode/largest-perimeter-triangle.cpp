class Solution {
public:
    
    bool validTriangle(const vector<int>& nums, int side1, int side2, int side3){
        return nums[side1] < (nums[side2]+nums[side3]);
    }
    
    int largestPerimeter(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());
        
        int size = nums.size();
        int perimeter = 0;
        
        for(int i = size-1; i > 1; i--){
            if(validTriangle(nums, i, i-1, i-2)){
                // since we know that
                // nums is sorted
                // and nums[i >= i-1 >= i-2]
                // if we are not able to get a valid triangle
                // it means that we can't form a triangle so we need to 
                // move the window back
                perimeter = nums[i] + nums[i-1] + nums[i-2];
                break;
            }
        }
    
        return perimeter;
    }
};
