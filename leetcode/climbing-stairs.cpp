// recursive solution

class Solution {
public:
    
    
    unordered_map<int,int> step;
    
    int climbStairs(int n) {
        if(n > 1){
            if(step.find(n) == step.end()){
                step[n] = climbStairs(n-1) + climbStairs(n-2);
            }
            return step[n];
        } else {
            return 1;
        }
    }
};

// iterative solution

class Solution {
public:
    
    int climbStairs(int n) {
       
        if(n == 1){
            return 1;
        }
        
        if(n == 2){
            return 2;
        }
        
        vector<int> steps(n+1,0);
        steps[1] = 1;
        steps[2] = 2;
        
        
        
        for(int i = 3; i <= n; i++){
            steps[i] = steps[i-1] + steps[i-2];
        }
        
        return steps[n];
    }
};

// for 1 step 1 ways only
// for 2 steps 1,1 or 2 so 2 ways
// for 3 steps 1,1,1 or 1,2 or 2,1 so 3 ways
// for 4 steps 3 ways to climb 3 steps + 2 ways to climb 2 steps so 5 ways 
// hence the reccurance is as follows
// for n steps it can be ways(n) = ways(n-1) + ways(n-2) steps
// since only steps 1 or 2 are possible
// so its something like a fibbonachi series
