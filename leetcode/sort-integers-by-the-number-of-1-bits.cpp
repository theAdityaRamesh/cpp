


class Solution {
public:   
    
        static bool compare(int i, int j){
        
        // store i<j
        // incase the ones are equqal
        bool ans = i<j;
        int onesi = 0;
        while(i){ // left shift i
            onesi += i&1; // add 1 1 if i is odd
            onesi -= j&1; // left shift j ans sub 1 if j is odd
            j>>=1;
            i>>=1;
        }
        
        //if j > i
        // do the remaining shifts
        // this is not requireed for sorting by number of ones
        // but we can get equal case here so it has to be done
        while(j){
            onesi -= j&1;
            j>>=1;
        }    
            
        if(onesi == 0){
            return ans;
        } else{
            return onesi < 0;
        }
    }
    
    vector<int> sortByBits(vector<int>& arr) {
        // use the inbuilt sort fun ans custom comparaotot
        // time complexity O(nlog*64/32)
        sort(arr.begin(), arr.end(), compare);
        return arr;
    }
};
