// better solution
// use binary search twice
// if we find index = target during search
// store that 
// to find start
// move left
// to find end 
// move right
// after finding match

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        
        
        int size = nums.size();
        if(size == 0){
            return {-1,-1};
        }

        if(size == 1){
         if(nums[0] == target){
             return {0,0};
         } else {
             return {-1,-1};
         }
        }
      
        
        if(target < nums[0] || target > nums.back()){
            return {-1,-1};
        }
               
        int left = 0;
        int right = size-1;
        int mid ;
        int start = -1;
        int end = -1;
        
        while(left <= right){
            mid = left +(right-left)/2;
            if(nums[mid] == target){
                start = mid;
            }
            
            if(nums[mid] >= target){// move left after match
                right = mid - 1;
            } else{
                left = mid + 1;
            }
        }
        
        left = 0;
        right = size-1;
        
        while(left <= right){
            mid = left + (right-left)/2;
            if(nums[mid] == target){
                end = mid;
            }
            
            if(nums[mid] <= target){ // move right after match
                left = mid+1;
            } else {
                right = mid-1;
            }
        }       
        
        return {start, end};
    }
};

// basic solution
// binary search to find the index
// linear search above and below index to find start and end

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        
        
        int size = nums.size();
        if(size == 0){
            return {-1,-1};
        }

        if(size == 1){
         if(nums[0] == target){
             return {0,0};
         } else {
             return {-1,-1};
         }
        }
      
        
        if(target < nums[0] || target > nums.back()){
            return {-1,-1};
        }
               
        int left = 0;
        int right = size-1;
        int mid ;
        
        while(left <= right){
            mid = left +(right-left)/2;
            if(nums[mid] == target){
                break;
            } else if(nums[mid] > target){
                right = mid-1;
            } else{
                left = mid+1;
            }
        }
        
        if(nums[mid] != target){
            cout << "here";
            return {-1,-1};
        }
        
        int start = mid;
        int end = mid;
        while(start >= 0 && nums[start] == target){
            start--;
        }
        
        while(end < size && nums[end] == target){
            end++;
        }
        
        return {start+1, end-1};
    }
};
