//leetcode.com/problems/permutations/

class Solution {
public:
    
    vector<vector<int>> result; // intialize results vector
    vector<int> rArrT, iArrT; // intialize temp vectors
    
    // the function gPermute works as follows
    // gPermute([1 2 3], [])

    //  gPermute([2 3], [1])

        // gPermute([2], [1 3])
    
            // gPermute([], [1 3 2]) -> @ this pt rArr.size() == 0 so push and into result vector
    
        // gPermute([3], [1 2]])
    
            // gPermute([], [1 2 3])

    //  gPermute([1 3], [2])

    //  gPermute([1 2], [3])


    void gPermute // helper function
        (vector<int> rArr, vector<int> iArr){
        
        if(rArr.empty()){            
            result.push_back(iArr); 
            return;
        }        
        
                
        if(rArr.empty() == false){
            for(int i = 0; i < rArr.size(); i++){

                rArrT = rArr;
                rArrT.erase(rArrT.begin()+i); // [1 2 3] - > [2 3]
                
                iArrT = iArr; // []
                iArrT.push_back(rArr[i]); // [] -> [1]
                
                   
                gPermute(rArrT, iArrT ); // [2 3] , [1]                
            }
            
        }        
        
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        
       // calling the helper function
        
        if(nums.size() == 1){
            result.push_back(nums);
            return result;
        }
        
        vector<int> empty;
        gPermute(nums, empty);
            
        return result;
    }
};

// method 2
// more elegant
// saves space due to non creationg of temp arrays

class Solution { 

    public:
    
    // [ 1 2 3] indx = 0
    // [1 2 3] i=0,indx=0  ; [2 1 3] i=1,indx=0 ; [ 3 2 1] i=2,indx=0
    
    // [1 2 3] i=0,indx=0  ;
    //      [ 1 2 3] i=1,indx=1 ; [ 1 3 2] i=2,indx=1 

    // [2 1 3] i=1,indx=0
    //      [2 1 3] i=1,indx=1 ; [2 3 1] i=2, indx=1
            // [ 2 1 3] i=2,indx=2;
                // [2 1 3] indx=3 result.push_back([2 1 3])


    // [3 2 1] i=2,indx=0
    //      [3 2 1] i=1, indx=1 ; [ 3 1 2] i=2,indx=1


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

