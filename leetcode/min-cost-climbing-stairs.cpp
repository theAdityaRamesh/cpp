class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        
        vector<int> steps(cost.size(), 0);
        
        if(cost.size() == 1){
            return cost[0];
        }
        
        if(cost.size() == 2){
            return min(cost[0],cost[1]);
        }
        
        // since we can start from 0 or 1 index
        // cost to reach 0 or 1 index = cost[i]
        
        steps[0] = cost[0]; 
        steps[1] = cost[1];
        
        // we will start checking from the 3rd step
        // @ each step we check
        // if its cheapear to go from i-1 th step to ith step
        // or i-2 th step to the ith step
        // we compare cost of
        // i-1 + i v/s i-2 + i
        // at the end we have a dummy step of cost 0
        
        
        for(int i = 2; i < steps.size(); i++){
            steps[i] = min(steps[i-1] + cost[i], steps[i-2] + cost[i]);
        }
        
        // hence return min(end-1, end-2) cost
        return min(*(steps.end()-1), *(steps.end()-2));    }
};
