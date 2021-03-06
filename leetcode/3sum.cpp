// faster method O(n^2) almost

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        vector<vector<int>> res;
        vector<int> ans;
        
        int size = nums.size();
        
        // if size of input is < 3
        // not possible to find a triplet
        if(size < 3) {
            return res;
        }
        
        // sort array to enable faster search
        sort(nums.begin(), nums.end());

        if( (nums[0] > 0) || (nums[size-1] < 0) ){
            // if minimum is +ve or maximum is -ve
            // its not possible to sum to zero
            // return empty vector
            return res;
        } 
        
        
        else {
        
            // fix first element
            for(int i = 0; i < nums.size() && nums[i] <= 0; i++){
                
                // skip duplicate elements
                if( i > 0 && nums[i] == nums[i-1]){continue;}
                
                // fix left pointer adjacent to first pointer
                int left = i+1;
                // fix right pointer at end
                int right = size-1;
                
                while( left < right){
                    
                    // if zero sum triplet found update result vector
                    if(nums[left] + nums[right] + nums[i] == 0){
                        res.push_back( {nums[i], nums[left], nums[right]} );
                        
                        // skip forward till we get different element than
                        // prev match
                        while(left < nums.size()-2 && nums[left+1] == nums[left]){
                            left++; // skip duplicates
                        } 
                        
                        // skip backword
                        while(right >0 && nums[right] == nums[right-1]){
                            right--; // skip duplicates
                        }
                        
                        // update left and right 
                        // since loop ends when next element is distinct
                        // so left right still on prev match 
                        left++;
                        right--;
                        
                    } else {
                        
                        // if sum is > than 0 then we have to reduce so
                        // move left from the end as array is sorted in 
                        // ascending order
                        if( nums[left] + nums[right] > -nums[i]){
                            right--;
                        } else { left++; } // sum < target increase sum move right
                        
                    }
                    
                }  
            }
            
        }
    
        return res;
       
    }
};

// MI slower method O(n^3) almost

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
