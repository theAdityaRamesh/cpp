class Solution {
public:
    bool isHappy(int n) {
        // implement bit array instead of hash map
        vector<int> hashMap(731,0);
        
        while(n != 1){
            
            int squares = 0;
            // calculate sum of squares
            while(n){
              squares +=  (n%10)*(n%10);
              n /= 10;
            }
            
            n = squares;
            // if already present in hashmap
            // it indicates we are moving in a loop
            // return false
            if( hashMap[squares] == 1){
                return false;
            } else {
                // otherwise
                // it means first encounter
                // mark as encountered in hashmap
                hashMap[squares] = 1;
            }
        }
        return true;
    }
};
