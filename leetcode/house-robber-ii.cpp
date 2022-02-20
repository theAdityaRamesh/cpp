class Solution {
public:
    int rob(vector<int>& nums) {
        
        int size = nums.size();
        

        if(size == 1){return nums[0];}

        if(size == 2){return max(nums[0], nums[1]);}

        if(size == 3){return *max_element(nums.begin(), nums.end());}

        int maxLoot;
        
        // use first house
        // leave last house
        // we do house robber on 1st to 2nd last house
        // since we cant loot first and last house together
        // we split the problem by excluding the first/ last house
        // the only difference in the circular one and linear problem
        // is that we cant loot both the first and last houses together
        vector<int> loot(size,0);
        loot[0] = nums[0];
        loot[1] = max(nums[1], nums[0]);
        for(int i = 2; i < size-1; i++){
            loot[i] = max(loot[i-1], loot[i-2]+nums[i]);
        }
        
        // use last house
        // leave first house
        maxLoot = loot[size-2];
        nums[2] = max(nums[1], nums[2]);
        for(int i = 3; i < size; i++){
            nums[i] = max(nums[i-1], nums[i-2]+nums[i]);
        }
        
        return max(maxLoot, nums[size-1]);
        ;
    }
};
