class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
        int size = nums.size();
        
        sort(nums.begin(), nums.end());        
        vector<vector<int>> res;
        
        if(size < 4){
            return res;
        }
        
        if(target >= 0 && nums[0] > target){
            return res;
        }
        
        if(target < 0 && nums[0] > 0){
            return res;
        }
        
        for(int i = 0; i < size; i++){
            
            if(i > 0 && nums[i] == nums[i-1]){
                continue;
            } 
            
            for(int left = i+1; left < nums.size(); left++){
                
                if(left > i+1 && nums[left] == nums[left-1]){
                    continue;
                }
                
                int low = left+1;
                int high = size-1;
                
                while( low < high ){
                    
                    if(nums[low] >= 1000000000 || nums[low] <= -1000000000){
                        break;
                    }
                    
                    int sum = nums[i] + nums[left] + nums[low] + nums[high];
                    if( sum  == target){
                        res.push_back({ nums[i], nums[left], nums[low], nums[high] });
                        
                        while( low < size-2 && nums[low] == nums[low+1]){ low++ ; }
                        while( high > 1 && nums[high] == nums[high-1]){ high--; }
                        
                        low++;
                        high--;
                        
                    } else {
                        low = sum < target ? low+1 : low;
                        high = sum > target ? high-1 : high;
                    }
                }
                
            }
            
        }
        
        return res;
    }
};
