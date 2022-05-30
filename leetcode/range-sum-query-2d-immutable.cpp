// method 1 using prefix sum
// O(mn) storgate
// O(m) query

class NumMatrix {
public:
    vector<int> prefixSum;
    int mSize ;
    
    NumMatrix(vector<vector<int>>& matrix) {
        prefixSum.reserve(matrix.size()*matrix[0].size());
        mSize = matrix[0].size();
        int sum = 0;
        // calculate sums upto every index O(mn) time
        // O(mn) memory
        for(int i = 0; i < matrix.size()*matrix[0].size(); i++){
            sum += (matrix[i/matrix[0].size()][i%matrix[0].size()]);
            prefixSum.push_back(sum);
        }        
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        
        int ans = 0;
        // to get the ans calulate the row sum using the precomputed
        // prefix sums. O(m) time
        for(int row = row1; row <= row2; row++){
            ans +=  getRowSum(row, col1, col2);
            
        }
        return ans;
    }
    
private :
    
    int getRowSum(int row, int col1, int col2){
        
        if(getIndx(row,col1) == 0){
            return prefixSum[getIndx(row, col2)];
        } else {
            return prefixSum[getIndx(row,col2)] - prefixSum[getIndx(row,col1)-1];
        }
        
    }
    
    int getIndx(int row, int col){
        return row*mSize + col;
    }
    
    
};

// method 2 using storing rectangles
// O(mn) storage O(1) query

class NumMatrix {
public:
    
    vector<vector<int>> sum;
    
    NumMatrix(vector<vector<int>>& matrix) {   
        vector<vector<int>> mat(matrix.size()+1, vector<int> (matrix[0].size()+1,0));
        
        for(int row = 0; row < matrix.size(); row++){
            for(int col = 0; col < matrix[0].size(); col++){
                mat[row+1][col+1] = mat[row][col+1] + mat[row+1][col] + matrix[row][col] - mat[row][col];
            }
        }
        
        sum = move(mat);
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return sum[row2+1][col2+1]-sum[row1][col2+1]-sum[row2+1][col1]+sum[row1][col1]; 
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
