class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        
        int i=0,prev = 0;
        
        for(i = 0; i < nums.size(); i++){
            if(nums[i] != val){
                swap(nums[prev++],nums[i]);
            } 
        }
        
        return prev;
    }
};
