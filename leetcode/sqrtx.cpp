class Solution {
public:
    int mySqrt(int x) {
        
        // 0*0 = 0
        if(x == 0){
            return 0;
        }

        
        // sqrt x is always 
        // less than x and > 1
        long next = x;
        long prev = 1;
        long mid;
        // so binary search
        // bw 1 and x
        while(prev+1 != next){
            mid = prev+(next-prev)/2;
            if(x == mid*mid){
                return mid;
            }
            if(x > mid*mid){
                prev = mid;
            } else{
                next = mid;
            }
        }
        
        
        return prev;
    }
    
    // another way is to keep subtracting odd numbers
    // till we reach 0 for a perfect square
    // and till we reach -ve for a imperfect square
    // the ans is the number of subtrations
    // this is because summ of k odd nums is k^2
};
