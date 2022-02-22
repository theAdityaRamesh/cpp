class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        
        int N = nums.size();
        int sum = 0;
        int sumMin = 0;
        int sumMax = 0;
        int maxSum = INT_MIN;
        int minSum = INT_MAX;
        int end;
        
        // scan from start to end
        for(int i = 0; i < N; i++){
            sumMax = max(sumMax+nums[i], nums[i]);
            maxSum = max(maxSum, sumMax);
            sumMin = min(sumMin+nums[i], nums[i]);
            minSum = min(sumMin, minSum);
            sum += nums[i];
        }       
        
        // keep track of min subarray sum
        // max subarray sum and total sum
        // if all nos are -ve then we will return min of them all
        // if all nos are -ve then maxSum will also be -ve
        if(maxSum < 0){
            return maxSum;
        } // so checking here
        // otherwise
        // we will either have the max subarray between the start and end
        // or wrapped around the start and end
        // we can use the minimum subarray sum and subtract from the total
        // sum to find the wrapped around sum
        return max(maxSum, sum - minSum);

    }
};
