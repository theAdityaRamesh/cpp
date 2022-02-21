class Solution {
public:
    int jump(vector<int>& nums) {
       
        int size = nums.size();        
        if(nums[0] == 0 || size == 1){
            // if @ first place
            // we cant jump
            // return 0
            // impossible case
            return 0;
        }
        
        if(nums[0] > size-1){
            // if at first place max jump len is >
            // than size of array
            // we can cover array in single 
            // jump
            // return 1
            return 1;
        }
        
        
        int jumps = 0;
        int jumpIndx = nums[0];
        int next = -1 ;
        for(int i = 0; i < size-1; i++){
            // @ every index assume that we jump the max possible
            // calculate the next position based on that
            // take max with the prev max jump pos
            // based on prev indices
            next = max(i+nums[i], next);
            if(i == jumpIndx){
                // if we reach the jumpIndx pos
                // it means we have taken 1 jump
                jumps++;
                // update the jumpIndex with the next
                // maximum possible index which is reacheable
                jumpIndx = next;
            }
        }
        
        // if @ end of array we are able to cross
        // or reach last index
        // we must have take one jump from prev
        // max reaheable position
        if(jumpIndx >= size-1){
            return ++jumps;
        }
                
        return jumps;
    }
};
