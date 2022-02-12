class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        
        int distance = INT_MAX/2;
        int closest = INT_MAX/2;
        int size = nums.size();
        // sort araray to enable faster search
        sort(nums.begin(), nums.end());
               
        // first pointer
        // moves linearly from 0 -> end
        for(int i = 0; i < nums.size(); i++){
            
            // skip duplicates 
            if(i > 0 && nums[i] == nums[i-1]){
                continue;
            } else {
                
                // set left pointer adjacent to 1st pointer
                int left = i+1;
                // set right to end of array
                int right = size-1;
                
                while(left < right){
                    
                    // calculate cuurent sum
                    int sum = nums[i] + nums[left] + nums[right];
                    
                    // if we get exact match stop searching
                    if( sum == target){
                        return sum;
                    }
                    
                    // otherwise find distance from target
                    if( abs(sum - target) < distance ){
                        // update closest if distance is less than prev match
                        distance = abs(sum-target);
                        closest = sum;
                    } 
                    
                    // can also be written as
                    // left += sum < target
                    // sum < target evaluates to true or false
                    // typecast to int its 1 or 0
                    // also += has less precedence than < > comparison
                    // hence it becomes left += 1 / 0
                    left = sum < target ? left+1 : left;
                    right = sum > target ? right-1 : right;

                }
                
            }
            
        }
     
        return closest;
    }
};
