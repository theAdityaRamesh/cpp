class Solution {
public:
    int findMin(vector<int>& nums) {
        
        int size = nums.size();        
        int left = 0;
        int right = size - 1;
        int mid;
        
        // 0 1 2 3 4 5 6
        while(right - left > 1){
            mid = (right-left)/2 + left;
            if(nums[mid] > nums[right] ){
                // 4 5 6 3
                // l = 4
                // m = 6
                // r = 3
                left = mid;
            } else { // mid < right
                // 5 4 3 0 1 2
                right = mid;
            }            
        }
        
        return min(nums[right], nums[left]);
        
    }
};
