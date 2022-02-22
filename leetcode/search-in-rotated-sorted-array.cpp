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
                if(nums[mid] > nums[left]){ // left < mid < target
                    left = mid + 1; 
                } else{ // left > mid & mid < target
                    if(target <= nums[right]){ // mid < target < right
                        left = mid + 1;
                    } else { // mid < target < left
                        right = mid - 1;
                    }
                }
            } else if( target < nums[mid]) { 
                if(nums[mid] < nums[right]){ // target < mid < right
                    right = mid - 1;
                } else { 
                    if(target >= nums[left]){ // left < target < mid
                        right = mid-1;
                    } else{
                        left = mid + 1; // mid > target > right
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
