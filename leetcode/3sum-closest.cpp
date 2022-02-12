class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        
        int closest = INT_MAX/2;
        int size = nums.size();
        sort(nums.begin(), nums.end());
               
        
        for(int i = 0; i < nums.size(); i++){
            
            if(i > 0 && nums[i] == nums[i-1]){
                continue;
            } else {
                int left = i+1;
                int right = size-1;
                
                while(left < right){
                    
                    int sum = nums[i] + nums[left] + nums[right];
                    if( abs(sum - target) < abs(target-closest) ){
                        closest = sum;
                    } 
                    
                    if( sum - target < 0 ){
                        left++;
                    } else {right--;}

                }
                
            }
            
        }
     
        return closest;
    }
};
