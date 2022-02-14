// method 2
// using reversal
// O(n) time complexity
// key idea is that the last index after shifting will be at the kth position
// step 1 reverse entire array
// step 2 put last index in correct postion by reverse(begin, begin+k)
// step 3 put first postion in coorect place by reverse(begin+k, end)

class Solution {
public:
    
    void rotate(vector<int>& nums, int k) {
        
        int  N = nums.size();
        
        if(k%N ==0){
            return;
        }
        
        if(k > N){
            k = k%N;
        }
        
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin()+k);
        reverse(nums.begin()+k, nums.end());
    }
};


// method 1
// using cyclic shifrs
// O(1) space O(nk) time

class Solution {
public:
    
    int gcd(int m, int n){
        if(n == 0){
            return m;
        } return gcd(n, m%n);
    }
    
    void rotate(vector<int>& nums, int k) {
        
        int N = nums.size();
        vector<int> temp = nums;
        
        if(k%N == 0){
            return; // if k = mN
        }
        
        if(k > N){
            k = k%N; // if k > N
        }            // take modulus
                    // now k < N
        
        int cycles;
        int cycles1;
        int startIndx = 0;

        // outer loop will repear gcd(N,k) times
        // for 8,6 it will repeat 2 times
        // inner loop will repeat N/gcd(N,k) times
        // for 8,6 it'll be 4 times
        // (0+6)%8 = 6 -> (6+6)%8 = 4, (4+6)%8 =2, (2+6)%8 = 0
        // similarly for 1 , 7 , 5, 3
        
        cycles = gcd(N, k); 
        cycles1 = N/cycles;
        
        
        for(; cycles > 0; cycles--){                
           
            int indx = startIndx;
            int swapIndx;
            int prev = nums[startIndx];
            int next;
            
            for(int it = cycles1 ;it > 0; it--){
                swapIndx = (indx+k)%N;
                next = nums[swapIndx];
                nums[swapIndx] = prev;
                indx = swapIndx;
                prev = next;                
            } 
            startIndx++;
        }
    }
};
