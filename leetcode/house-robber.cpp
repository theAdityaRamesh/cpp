class Solution {
public:
    
    unordered_map<int,int> maxLootFromPast = {};
    int maxLoot = 0;
    
    void burgle(const vector<int>& nums, int prevHouse){
        
        if(prevHouse+2 > nums.size()-1){
            if(maxLootFromPast[prevHouse] > maxLoot){
                maxLoot = maxLootFromPast[prevHouse];
            }
            return;                
        }
            
        
        for(int i = prevHouse+2; i < nums.size(); i++){
            
            if(maxLootFromPast.find(i) != maxLootFromPast.end()){
                if(maxLootFromPast[i] < maxLootFromPast[prevHouse] + nums[i]){
                    maxLootFromPast[i] = maxLootFromPast[prevHouse] + nums[i];
                } else{
                    return;
                }
            } else{
                maxLootFromPast[i] = nums[i] + maxLootFromPast[prevHouse]; 
            }
            
            burgle(nums, i);
        }
               
    }
    
    int rob(vector<int>& nums) {
        
        int N = nums.size();
        // max # of houses that can be robbed is N/2
        // after robbing the first house
        // we can choose any house that is not a neighbour
        // for 1st house N ways
        // for 2nd house N-3 ways (1 burgaled already + 2 neighbours)
        // for 3rd house N - 2 - 4 = N-6 options
        // ... for N/2th house either no option or 1 option if N odd
        // basically 
        // maxLoot for N + 1 th house burgalry is max loot from N houses + maxLoot for
        
        if(N == 1){
            return nums[0];
        }
        
        if(N == 2){
            return nums[nums[1]>nums[0]];
        }
        
        
        for(int i = 0; i <= nums.size()/2; i++){
            maxLootFromPast[i] = nums[i];
            // we store max loot that can be obtained by choosing
            // ith house as the first house
            // since first house is to be chosen before N/2
            // we scan only till N/2
        }
        
        for(int i = 0; i <= nums.size()/2; i++){
            int prevHouse = i;
            burgle(nums, prevHouse);
        }
        
        
        return maxLoot;
    }
};
