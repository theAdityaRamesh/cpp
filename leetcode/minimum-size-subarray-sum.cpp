class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        
        int sum = 0;
        int size = nums.size();
        int ans = size;
        int start = 0;
        
        // scan from left to right
        // change the end of the SW after each iteration
        for(int end = 0; end < size; end++){
            // include current element in the sum
            sum += nums[end];
            // if the sum is >= target
            if(sum >= target){
                // shrink the SW
                // by movinf the start of the window forward
                // till the sum goes below target
                while(sum >= target){
                    sum -= nums[start++];
                } ans = min(ans, end-start+2);
                // after each reduction update the ans
                // here size of SW is end-start+1 but
                // but at the end start++ so end-start+2
            }
        }
        
        // if the SW spans the entire array
        // if the sum < target
        // there exist no subarrays > the target
        // return 0
        if(start == 0 && sum < target){
            return 0;
        }
        
        return ans;
        
    }
};
