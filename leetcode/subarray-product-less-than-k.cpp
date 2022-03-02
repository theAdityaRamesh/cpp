class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k<=1)
            // if k is 1 or zero
            // since all the subarray elements are +ve
            // so it is not possible to form a product 
            // which is < 1
            return 0;
        int ans=0;
        int start=0,end=0,product=1;
        int n=nums.size();
        // scan from left to right
        // we check for the largest possible SW
        // at the position of end
        for(; end<n; end++){
            product*=nums[end];
            while(product>=k){
                product/=nums[start++];
            }// here we shrink the sliding window
            // if the product gets too large
            if(product<k)
                // if we can find a SW of size end-start+1
                // then all the SW of size < end-start+1 are
                // also valid so it means end-start+1 SW are possible
                // so we increase the ans by that sum
                ans+=(end-start)+1;
        }
        return ans;
    }
};
