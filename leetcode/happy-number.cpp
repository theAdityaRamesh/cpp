// solution 1
// use cycle detection
// any to pointers which are moving with coprime speeds
// will eventually meet each other moving in a cycle

class Solution {
public:
    
    int happyTransform(int n){
        int squares = 0;
        while(n){
          squares +=  (n%10)*(n%10);
          n /= 10;
        }
        
        return squares;
    }
    
    bool isHappy(int n) {
        
        int slow = n;
        int fast = n;
        while( fast != 1){
            // slow pointer moves at 1 /iter
            // fast pointer moves at 2 /iter
            slow = happyTransform(slow);
            fast = happyTransform(fast);
            fast = happyTransform(fast);
            // cout << slow << " " << fast << endl;
            if(slow == fast){
                break;
            } 
        }
        
        // if fast = 1 then its a happy num
        // otherwise unhappy :(
        return fast == 1;

// solution 2
// use a bit array to mark already visited nums

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
