class Solution {
public:
    bool canJump(vector<int>& nums) {
       
        int next = 0, curr = 0;
        
       for(int i = 0; i < nums.size()-1; i++){
           next = max(next, nums[i]+i);
           if(curr == i){
               curr = next;
           }
       }

       curr = curr-int(nums.size()-1) >= 0 ? 1 : 0;
       return curr;
    }
};
