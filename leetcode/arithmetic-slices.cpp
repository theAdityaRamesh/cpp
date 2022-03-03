class Solution {
public:
    
    int slices(int start, int end){
        return (end-start+1-2)*(end-start)/2;
    }
    
    int numberOfArithmeticSlices(vector<int>& nums) {
        
        int size = nums.size();
        // since min len of slice is 3
        if(size < 3){
            return 0;
        }
        
        // start with ans = 0
        int ans = 0;
        // start of the progression is at 0
        int start = 0;
        // scan from 2
        for(int i = 2;i < size; i++){
            // if there is a common diffrecen b/w
            // i-2 i-1 i then we have a AP 
            if(nums[i] - nums[i-1]  == nums[i-1] - nums[i-2]){
                // move the pointer forward to i+1
                // by checkking the next element first
                // i-1 i i+1
                while(i+1 < size && nums[i+1]-nums[i] == nums[i]-nums[i-1]){
                    i++;                    
                }
                // at the end of the loop we have the last element of the AP
                // now for a AP of size N
                // we have 1 slive of size N
                // 2 slices of size N-2
                // 3 slives of size N-3
                // ... and so on till size 3
                // so we have 1+2+3 .. N-2
                // so its (N-2)(N-2+1)/2 
                // nums of slices
                // so ans is incremented by that
                ans += slices(start,i);
                // now the start is set to i
                // i is the last element in the AP slice
                start = i;
                // we increment i here becaise
                // start and i shud have a diff of 2 index
                i++; // here i is ahead by one
                // and when it goes back to the loop
                // it will increment again
            } else{
                // otherwise move the start of the window forward
                start++;
            }
        }
    
        return ans;
    }
};
