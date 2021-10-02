//leetcode.com/problems/trapping-rain-water/

class Solution {
    public:
    int trap(vector<int>& arr) {
     
        int max_indx = 0, max_element = -1, it = 0, water = 0;
        
        while(it < arr.size()-1){
            
            if(arr[it] > arr[it+1]){
                
                int j = it+1;
                max_indx = it+1;
                
                while(j < arr.size()){
                    
                    if(arr[j] > arr[it]){
                        max_indx = j;
                        break;
                    } else if(arr[j] > arr[max_indx]){
                        max_indx = j;
                    }
                
                    j++;
                }
                
                if(max_indx != it+1){
                    int height = min(arr[it], arr[max_indx]);
                    for(int k = it+1; k < max_indx; k++){
                        water += height - arr[k];
                    }
                }
                
                it = max_indx;
                continue;
            }
            
            it++;
        }
            return water;
    }
    
    
};

