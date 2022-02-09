class Solution {
public:
    
    int myPow(long x,int y){
        
        int ans = 1;
        
        while(y){
            
            if(y%2){ans *= x;}
            
            x *= x;
            y /= 2;
        } 
        
        return ans;
    }
    
    vector<int> grayCode(int n) {
        
        vector<int> gray(myPow(2,n));
        int i = 0;
        
        while(i < gray.size()){
            gray[i++] = i^(i>>1);
        }
        
     

        return gray;
    }
};
