//leetcode.com/problems/search-insert-position/

class Solution {
public:
    int searchInsert(vector<int>& arr, int target) {
        
        if(target < arr[0] || arr.empty()){
            return 0;
        }
        
        int head = 0, tail = arr.size()-1, mid = (head+tail)*0.5;
        while(head < tail){

            mid = (head+tail)/2;
            cout << head << " " << mid << " " << tail << endl;
            
            if(arr[mid] == target){
                return mid;
            } else {
                if(arr[mid] < target){
                    head = mid+1;
                } else {
                    tail = mid-1;
                }
            }
        }
    
        
    }
};
