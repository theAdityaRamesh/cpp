class Solution {
public:
    int singleNumber(vector<int>& nums) {
        
        int single = nums[0];
        
        // say nums = 4,2,2,1,1
        // 100 ^ 010 ^ 010 ^ 001 ^ 001
        // XOR is even parity
        // hence duplicates will go to zero
        
      
        for(int i = 1; i < nums.size(); i++){
            single ^= nums[i]; 
        }
        
        return single;
    }
};
