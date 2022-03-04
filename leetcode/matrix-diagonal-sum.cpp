class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        
        int rSize = mat.size();
        int row = 0;
        int sd = rSize-1;
        int sum = 0;
        // primary diag goes 0,0 1,1 2,2 ..
        // sec diag goes 0,rSize-1, 1,rSize-2, ...
        while(row < rSize){
            sum += (mat[row][row] + mat[row][sd]);
            row++;
            sd--;
        }
    
        // if odd size matrix
        // pd and sd intersect
        // so remove the centre element
        if(rSize&1){
            sum -= mat[rSize/2][rSize/2];
        }
        
        return sum;
    }
};
