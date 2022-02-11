class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        vector<vector<int>> res;
        vector<int> gray(nums.size(),0);
        vector<int> ans;
        
        if(nums.size() < 3) {
            return res;
        }
        
        int curr = 0;
        int sum = 0;
        sort(nums.begin(), nums.end());
        
        int min = nums[0];
        int max = nums[nums.size()-1];
        
      
        
        if( (min > 0) || (max < 0) ){
            return res;
        } 
        
        
        else {
        
            for(int i = 0; nums[i] <= 0; i++){
                
                if( i > 0 && nums[i] == nums[i-1]){
                    continue;  
                }
                
                for(int left = i+1; left < nums.size();left++){                    
                    
                    if(left > i+1 && nums[left] == nums[left-1]){
                        continue;
                    }
                    
                    for(int right = left+1; right < nums.size(); right++){
                        
                       if(right > left+1 && nums[right] == nums[right-1]){
                            continue;
                        }

                        if(nums[right] + nums[left] + nums[i] == 0){
                            
                            ans.push_back(nums[i]);
                            ans.push_back(nums[left]);
                            ans.push_back(nums[right]);
                            res.push_back(ans);
                            ans.clear();
                            
                        }   
                    }
                       
                }
            }
            
        }
    
        return res;
    }
};
