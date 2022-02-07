class Solution {
public:
    

    
    bool isPalindrome(int x) {
 
        if(x < 0) {return false;}
        if(x < 10) {return true;}
        
            int subX = 0, tX = x;

            while(tX) {  
                
                if(subX > INT_MAX/10){
                    return false;
                }
                
                subX = subX*10 + (tX%10);
                tX /= 10;
            } 
        
        return (x == subX);
      
    }
};
