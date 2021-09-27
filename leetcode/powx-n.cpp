// https://leetcode.com/problems/powx-n/

class Solution {
public:
    
    double myPow(double x, int n) {
        
        if(n==0 || x==1){return 1;}
        
        double res = 1;
        long N = n;
        while(n){
            
            if(n&1){
                res = x*res;
            }
            
            n /= 2;
            x *= x;
        }
        
        return N > 0 ? res : (1/res);        
    }
    
    
//     double myPow(double x, int n) {
//         if(n==0 || x==1){return 1;}
        
//         stack<double> prev;
//         long absN = abs(n);
//         long currentPow = 1;  
        
//         prev.push(x);
//         for(int i = 0; i < int(log2(absN)); i++){
//             x *= prev.top();
//             prev.push(x);
//             currentPow *= 2;     
//         }
        
//         absN -= currentPow;
//         while(absN > 0){
            
//             if(absN >= currentPow){
//                 x *= prev.top();
//                 absN -= currentPow;
//             } currentPow /= 2; prev.pop();
           
//         }
        
//         return n > 0 ? x : (1/x);
//     }
};
