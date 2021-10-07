//leetcode.com/problems/search-insert-position/

class Solution {
public:
    int searchInsert(vector<int>& arr, int target) {
        
        if(target < arr[0] || arr.empty()){
            return 0;
        } // handles values larger than array
        
        if(target > arr[arr.size()-1]){
            return arr.size();
        } // handles values smaller than array

        // handles values in array
        
        int head = 0, tail = arr.size()-1, mid = (head+tail)*0.5;
        while(head < tail){

            mid = head + (tail-head)/2;
            // to avoid overflow
            // for large arrays
            
            if(arr[mid] == target){
                return mid; // binary search
            } else {
                if(arr[mid] < target){
                    head = mid+1; 
                } else {
                    tail = mid-1;
                }
            }
        }
        
        // now the loop breaks when head = tail
        // now we choose to return head because mid does not get updated in the last iteration
        // if the target is larger then head then it will be next to it
            // as we have narrowed down the range to a single element
            // head and tail represent the possible values in which the target can exist
        // else it will be at head
        
        head = arr[head] < target ? head+1 : head;
        return head;
    }
};
