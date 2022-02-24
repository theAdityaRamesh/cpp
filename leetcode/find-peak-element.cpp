class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int left = 0;
        int size = nums.size();
        int right = size-1;
        int mid;
        
        // if size = 1
        // the only element is the peak
        if(size == 1){
            return 0;
        }
        
        // if size is 2
        // we return max of the 2
        if(size == 2){
            return nums[1] > nums[0];
        }
        
        // if first element is larger than second
        // it is a peak
        if(nums[0] > nums[1]){
            return 0;
        }
        
        // if last element is larger than 
        // 2nd last then it is a peak
        if(nums[size-1] > nums[size-2] ){
            return size-1;
        }
        
        // if peak is not the first or last element
        while(left <= right){
            // check middle of array
            mid = (right-left)/2 + left;
            
            // if middle is peak return
            if(nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1]){
                return mid;
            } else {
                // is nums is increasing to the right
                // climb right
                if(nums[mid] < nums[mid+1]){
                    left = mid;
                } else {
                // otherwise climb left
                    right = mid;
                }
            }
        }
        
        return mid;
    }
};
