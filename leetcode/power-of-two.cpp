class Solution {
public:
    bool isPowerOfTwo(int n) {
        
        if(n <= 0){
            return false;
        }
        
        bool out = true;
        while(n > 1){
            if(n&1){
                out = false;
                break;
            }
            n /= 2;
        }
        
        return out;

    }
};

// we can also do
// return (n & n-1)
// since and power of 2 = 1000..00
// and 2^n -1 == 0111..111
