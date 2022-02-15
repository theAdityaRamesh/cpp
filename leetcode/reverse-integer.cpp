class Solution {
public:
    int reverse(int x) {
        
        int rev  = 0;
        //INT_MAX = 2147483471
        while(x){
            if(abs(rev) > INT_MAX/10){
                return 0; // if reversed is > int_max/10
            } // if we add any number to it, it becomes more than int_max
            rev = rev*10 + (x%10);
            x /= 10;
        }
        
        return rev;
    }
};
