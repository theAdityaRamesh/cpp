//O(n) implementation
// scan the array frmo left to right
// if zero ignore
// if non zero swap with pointer at front of array
// increment front pointer
// basically insertion sort

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        
        int size = nums.size();
        int nonZeroPointer = -1;
        int zeroPointer = -1;

        if(size == 1){
            return;
        }
        
        while(++zeroPointer < size){
            if(nums[zeroPointer] != 0){
                swap(nums[++nonZeroPointer], nums[zeroPointer]);
            }
        }
    }
        
};
