class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        int size = nums.size();
        
        if(size == 0){
            return -1;
        } 
        
        if(size == 1){
            if(nums[0] == target){
                return 0;
            } else  {
                return -1;
            }
        }
        
        int left = 0;
        int right = size-1;
        int mid;        
        while(left <= right){
            mid = left + (right-left)/2;
            
            if(target > nums[mid]){
                if(nums[mid] > nums[left]){
                    left = mid + 1;
                } else{
                    if(target <= nums[right]){
                        left = mid + 1;
                    } else {
                        right = mid - 1;
                    }
                }
            } else if( target < nums[mid]) {
                if(nums[mid] < nums[right]){
                    right = mid - 1;
                } else {
                    if(target >= nums[left]){
                        right = mid-1;
                    } else{
                        left = mid + 1;
                    }
                }
            } else {
                break;
            }            
        }
               
        if(nums[mid] == target){
            return mid;
        } 
        
        return -1;
    }
};
