class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        int size = arr.size();
        if(size == 2){
            return true;
        }
        
        sort(arr.begin(), arr.end());
        //sort the nums so they are in increasing order
        int d = arr[1]-arr[0];
        // commong difference
        for(int i = 2; i < size; i++){
           if(d != arr[i]-arr[i-1]){
               // if commong difference changes
               // then we cant form an AP
               return false;
           } 
        }
        
        return true;
    }
};
