//leetcode.com/problems/next-permutation/

// method - 1 - aditya
class Solution {
public:
    
    void printVector(const vector<int>& nums){
        for(int i=0; i < nums.size(); i++){
            cout << nums[i] << " " ;
        }
    }
    
    void findNextSmallestIndx(const vector<int>& nums,int& iter, int& maxIndx){
    
        maxIndx = -1;
        
        for(int it = nums.size()-1; it!= -1; it--){
            
            if(it == maxIndx) {
                    break;
            }
            
            for(int cit = it-1; cit != -1; cit--){
                
                if(cit == maxIndx) {
                    break;
                }

                if(nums[cit] < nums[it] && cit > maxIndx){
                    maxIndx = cit;
                    iter = it;
                }
            }
        }
        
        
    }
    
    void nextPermutation(vector<int>& nums) {
       
        if(nums.size() == 1){
            return;
        }
        
        int it, indx;
        // return the indices of the closest swap
        // start from last and keep scanning till you find first number smaller than current indx
        // save it as maxIndx
        // continue last - 1 and repeat 
        // if current Indx becomes maxIndx stop scanning and return maxIndx and number just larger than it
        findNextSmallestIndx(nums, it, indx);
        
        // swap the 2 numbs
        if(indx != -1){
            swap(nums[it], nums[indx]);
        }
        
        // sort after the swapped indx
        sort(nums.begin()+indx+1,nums.end());
    }
};





