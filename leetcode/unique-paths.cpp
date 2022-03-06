class Solution {
public:
    
   
    int uniquePaths(int m, int n) {
        
        // m+n-2 choose n-1
        // is (m+n-2)! / (n-1)!(m-1)!
        // (m+n-2)(m+n-1)..(m)/(n-1)!
        // so divide out the (n-1)!
        // to get ans
        long ans2 = 1;
        for(int i = 1; i < n; i++){
            ans2 *= m++;
            if(ans2%i == 0){
                ans2 /= i;
            }
        }        
        return ans2;        
    }
};
