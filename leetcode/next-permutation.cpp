//leetcode.com/problems/next-permutation/

class Solution {
public:
    
    void printVector(const vector<int>& nums){
        for(int i=0; i < nums.size(); i++){
            cout << nums[i] << " " ;
        }
    }
    
    int findNextSmallestIndx(const vector<int>& num, int cindx){
        for(int it = cindx-1; it != -1; it--){
            if( num[it] < num[cindx]){
                // return indx of next smallest number
                return it;
            }    
        }
        
        // largest number @ num[cindx] 
        return -1;
    }
    
    void nextPermutation(vector<int>& nums) {
       
        if(nums.size() == 1){
            return;
        }
       
        int indx = -1, cindx = nums.size()-1;
        
        for(int it = cindx; it != -1; it--){
            // get indx of next smallest number
            if(nums[it] == 0) { continue;}
            
            indx = findNextSmallestIndx(nums, it) ;
            if (indx != -1){
                // swap the current tracked element with the next smallest element
                swap(nums[indx],nums[it]);
                break;
            }
        }
        
      
        sort(nums.begin()+indx+1,nums.end());
        printVector(nums);
    }
};





