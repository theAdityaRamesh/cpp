// https://leetcode.com/problems/rotate-image/

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        
        int N = matrix[0].size();
        int temp;
        
        
        for(int r = 0; r < matrix.size()/2; r++){
            for(int c = r; c < N - r - 1; c++ ){
                
                temp = matrix[r][c];
                matrix[r][c] = matrix[N-c-1][r];
                matrix[N-c-1][r] = matrix[N-r-1][N-c-1];
                matrix[N-r-1][N-c-1] = matrix[c][N-r-1];
                matrix[c][N-r-1] = temp;
            }
        }
        
        return;
    }
};
