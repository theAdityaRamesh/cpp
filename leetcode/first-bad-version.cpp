//leetcode.com/problems/first-bad-version

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        
        if(isBadVersion(1)){
            return 1;
        }
        
        int head = 1, tail=n, mid;
        
        while(head<tail){
           
            mid = head + (tail-head)/2;
           
            if(isBadVersion(mid)){
                // mid is bad
                tail = mid-1;
            } else { 
                // mid is good
                // bad must be after mid
                head = mid+1;
            }
           
        }  
        
        // loop breaks when head = tail
        // now again we choose head cause mid is not updated
        // we just need to check one case where head+1 is bad
        // but head is good 
        // eg : 1 2 (3->bad) 4 5
        // h = 1 t = 5 mid = 3
        // mid(3) bad so h = 1 t = 2 m = 1
        // mid(1) good so h = 2 t = 2 loop breaks
        // now in this case the head ends up one before the bad so 
        // we check
        head = !isBadVersion(head) ? head+1 : head;
        return head;
    }
};
