class Solution {
public:
    
    void permute(vector<int>& arr, vector<vector<int>>& res, int ptr){
        
        // if we reach end of array 
        // save the arr and return
        if(ptr == arr.size()-1){
            res.push_back(arr);    
            return;
        }
        
        // proceed in lexicographic order
        // 1 2 3 4 ptr = 0 say
        // 1 2 3 4
        // 2 1 3 4
        // 3 1 2 4
        // 4 1 2 3
        for(int i = ptr; i < arr.size(); i++){                                                                      
            if(i != ptr && arr[i] == arr[ptr]){
                continue;
            }
            
            swap(arr[i], arr[ptr]);   
            permute(arr, res, ptr+1);
            // here we avoid swapping back to avoid the duplicates
            // since we check the ptr and the current i always
            // the prev swapped number is in the pointer position
            // so we avoid duplicates
            // another way to understand is that
            // we are genratating in lexicographic ordert
            // hence if we swap the duplicates we will end up with the same number
            // we need to push the next biggest number after the num in ptr
            // poisiton to get the next number
            // 1 2 3 4(ptr=0) -> 1 2 3 4(ptr=1) -> 1234(ptr=2) -> 1234(ptr=3)
            //                                  -> 1243(ptr=2) 
            //                -> 1 3 2 4(ptr=1) 
            // and so on ...
        }
        
       // restore the arr by doing cyclic shifts 
       for(int i = arr.size()-1; i > ptr; i--) {
           swap(arr[ptr],arr[i]);
       }
        
    }
    
    vector<vector<int>> permuteUnique(vector<int>& arr) {
        
        vector<vector<int>> ans;
        if(arr.size() == 1){
            return {arr};
        }
        
        // sort the initial array to get the duplicates together
        // the array is now sorted and it is has the least value possible with
        // the set of nums
        sort(arr.begin(), arr.end());
        permute(arr, ans, 0);
        return ans;
    }
};

