class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
         // recursive sol would be to recurse through all possible paths
        // take the minumum
        // here we store the recursion up to the ith row jth col using DP
        // for i,j -> i-1,j-1 || i-1,j
        // here since we are updating the cost by adding the previous row costs
        // we need not use any extra memeory 
        // can do it in place
        if(triangle.size() == 1){
            return triangle[0][0]; // if only 1 element then return that
        }
        
        int r = 1;     // row index
        int res = INT_MAX;
        int size = 0;
        while(r != triangle.size()){ // iterate from triangel[1] -> triangle[n-1]
            size = triangle[r].size(); // store size for repeated calc
            triangle[r][0] += triangle[r-1][0]; // for the first and last indices only 1 way to acess
            triangle[r][size-1] += triangle[r-1][size-2];  
            for(int c = 1; c < size-1; c++){ // for all the compare the 2 costs of j and j-1 the col
                triangle[r][c] += min(triangle[r-1][c-1], triangle[r-1][c]); // take minimum of the 2 and add the current cost
            }
            r++; // go to next row
        }
        
        // for last row scan thru the row
        // take the minimum cost
        for(int c = 0; c < size; c++){
            res = min(res, triangle[r-1][c]);
        }
        
        return res;
    }
};
