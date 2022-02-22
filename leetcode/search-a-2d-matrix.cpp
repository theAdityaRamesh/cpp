class Solution {
public:
    
    bool binarySearch(const vector<int>& row, int target){
        
        int left = 0;
        int right = row.size()-1;
        int mid = 0;
        
        while(left <= right){
            mid = left + (right-left)/2;
            if(row[mid] == target){
                return true;
            } else if(row[mid] > target){
                right = mid-1;
            } else {
                left = mid+1;
            }
        }
        
        return row[mid] == target;
    }
    
    
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int rowSize = matrix.size();
        int colSize = matrix[0].size();
        
        if(matrix[0][0] > target || target > matrix[rowSize-1][colSize-1]){
            return false;
        }
        
        int right = rowSize-1;
        int left = 0;
        int mid = 0;
        
        // binary search for the row in which target is most likely
        // to be found
        if(rowSize > 1){
            while(left <= right){
                mid = left + (right-left)/2;
                if(matrix[mid][0] == target){
                    return true;
                } else if(matrix[mid][0] > target){
                    right = mid-1;
                } else {
                    left = mid + 1;
                }
            }
        }

        if(matrix[mid][0] > target){
            mid--;
        }
        
        // binary search for the col in the found row
        return binarySearch(matrix[mid], target);
    }
};
