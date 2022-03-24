class Solution {
public:
    int brokenCalc(int startValue, int target) {
        
        // invert the problem
        // start from target
        // as long as target is > start value
        // if even divide by 2 -> 1 steps
        // if odd add 1 divide by 2 -> 2 steps
        // keep doing this till we go less than start value
        // then we can only add 1 to reach start value
        
        if(target <= startValue){
            return (startValue-target);
        }
        
        int steps = 0;
        while(target > startValue){
            steps += (target&1);
            target += (target&1);
            target >>= 1;
            steps++;
        }
        
        
        steps += (startValue-target);
        return steps;
    }
};
