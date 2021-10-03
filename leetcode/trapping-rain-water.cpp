//leetcode.com/problems/trapping-rain-water/

// How this algorithm works is it is bounding the height of the valley from the left and right.
// If currently leftMax < rightMax then we can use leftMax as the wall height because even if 
//     (a) there are bigger walls in between the minimum height is leftMax so more than leftMax water cannot be stored in any given index. 
//     (b) if there are smaller walls then they lie inside the valley so that's also not a problem.

// The algorithm progressively bounds the valley height from the left and right till both pointers cross each other 
// in which case we have checked the entire array and we can return the water units.

class Solution{
    public:
int trap(vector<int> arr){
    int a=0;
    int b=arr.size()-1;
    int water=0;
    int leftmax=0;
    int rightmax=0;
    
    while(a<b){
        leftmax = max(arr[a], leftmax);
        rightmax = max(arr[b], rightmax);
    
        if(leftmax<rightmax){
            water+=(leftmax-arr[a]);       // leftmax is smaller than rightmax, so the (leftmax-A[a]) water can be stored
            a++;
        }
        else{
            water+=(rightmax-arr[b]);
            b--;
        }
    }
    return water;
}
    
};








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

