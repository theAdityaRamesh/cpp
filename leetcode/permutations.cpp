//leetcode.com/problems/permutations/

class Solution {
public:
    
    vector<vector<int>> result;
    vector<int> rArrT, iArrT;
    
    void gPermute
        (vector<int> rArr, vector<int> iArr){
        
        if(rArr.empty()){            
            result.push_back(iArr);
            return;
        }        
        
                
        if(rArr.empty() == false){
            for(int i = 0; i < rArr.size(); i++){

                rArrT = rArr;
                rArrT.erase(rArrT.begin()+i);
                
                iArrT = iArr;
                iArrT.push_back(rArr[i]);
                
                   
                gPermute(rArrT, iArrT );
                

                
            }
            
        }        
        
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        
       
        
        if(nums.size() == 1){
            result.push_back(nums);
            return result;
        }
        
        vector<int> empty;
        gPermute(nums, empty);
            
        return result;
    }
};


class Solution { 

    public:
    
    void gPermute(int indx, vector<int> nums, vector<vector<int>>& result){
        
        if(indx == nums.size()){
            result.push_back(nums);
            return;
        }
        
        for(int i = indx; i < nums.size(); i++){
            swap(nums[i],nums[indx]);
            gPermute(indx+1, nums, result);
            swap(nums[i], nums[indx]);
        
            }
        
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
     
        vector<vector<int>> result;
        gPermute(0, nums, result);
        
        return result;
    }

};

