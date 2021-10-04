//leetcode.com/problems/remove-duplicates-from-sorted-array/

class Solution {
public:
    int removeDuplicates(vector<int>& arr) {
        
        if(arr.empty()){
            return 0;
        }
        
        int k = 0, curr = arr[0];
        
        for(int i = 1; i < arr.size(); i++){
            if(arr[i] != arr[k]){
                k++;
                arr[k] = arr[i];
            }
        }
        
        return ++k;
    }
};
