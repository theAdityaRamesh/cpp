// method 1 using prefix sum

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
