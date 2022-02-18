class Solution {
public:
   
    int rob(vector<int>& nums) {
        
        int N = nums.size();
        
        if(N == 1){
            return nums[0];
        } // if only 1 house return 1st house loot
        
        if(N == 2){
            return nums[nums[1]>nums[0]];
        }// if 2 houses we can rob 1st or 2nd 
        // return max loot
        
        // vector<int> loot represents the maximum loot after robbing each house
        vector<int> loot(N,-1);
        loot[0] = nums[0];
        for(int i = 1; i < N; i++){
            int pick = nums[i];
            if(i > 1){
                pick += loot[i-2];
            }
            loot[i] = max(pick,loot[i-1]);
        }
            return loot[N-1];
    }
};

// for 1st house loot = nums[0]
// for 2nd house we can choose either 1st or 2nd so we take max
// for 3rd hpuse we can choose 1,3 or 2
    // pick = loot in 3rd house + loot in 3-2 = 1th house
    // no pick is loot in 3-1 th house which is 2nd house loot
    // we'll choose the maximum of the 2
// for the 4th house we can choose 1,3 or 2,4
    // pick = loot in 4th house + loot (4-2) loot in 2nd house
    // no pick is loot in 3rd house and first house loot[i-1]
    // we'll take max of the 2
// and so on till we reach the last house


class Solution {
public:
    
    unordered_map<int,int> maxLootFromPast = {};
    int maxLoot = 0;
    
    // the burgle functions goes through all possible routes to loot the house
    // if we find that loot is increasing take that route
    // otherwise stop
    // if loot is increasing then check in the next house
    
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
