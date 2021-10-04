//leetcode.com/problems/remove-duplicates-from-sorted-array-ii/
class Solution {
public:
    int removeDuplicates(vector<int>& arr) {
        
        if(arr.empty()){return 0;}
        
        int k = 0, curr = arr[0], cnt = 1;
        
        for(int i = 1; i < arr.size(); i++){
            
            // non equal element found 
            // move pointer frwrd
            // replace with pointer
            if(arr[i] != arr[k]){
                cnt = 1;
                arr[++k] = arr[i];
                continue;
            } // equal element found
                
            if(cnt < 2){ // check cnt value
                cnt++;  // 1 duplicate allowed
                arr[++k] = arr[i];
                // place duplicate in crckt spot 
                // in front of prev unique 
                // it might be the case that there are lot of 
                // duplicates bwteern the prev uniq and duplicate
                // hence we need to update duplicate also
                // increase pointer // increase duplicate  
            }
                               
            // else
            // more than 1 duplicate found
            // ignore
        }
        
        return ++k;
    }
};
