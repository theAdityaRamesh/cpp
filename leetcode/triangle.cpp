class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
     
        vector<vector<int>> cost = triangle;
        
        // for i,j -> i-1,j-1 || i-1,j
        
        if(triangle.size() == 1){
            return triangle[0][0];
        }
        
        int r = 2;
        cost[1][0] += cost[0][0];
        cost[1][1] += cost[0][0];
        
        if(triangle.size() == 2){
            return min(cost[1][0], cost[1][1]);
        }
        
        
        int res = INT_MAX;
        while(r != triangle.size()){
            
            cost[r][0] += cost[r-1][0];
            cost[r][triangle[r].size()-1] += cost[r-1][triangle[r].size()-2]; 
            for(int c = 1; c < triangle[r].size()-1; c++){
                cost[r][c] += min(cost[r-1][c-1], cost[r-1][c]);
            }
            r++;
        }

        for(int c = 0; c < cost[r-1].size(); c++){
            res = min(res, cost[r-1][c]);
        }
        
        return res;
    }
};
