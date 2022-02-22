// basic solution 

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& mat) {
        
        
        
        // check rows
        for(int row = 0; row < 9; row++){
            vector<bool> check(9,0);
            for(int col = 0; col < 9; col++){
                
                if(mat[row][col] == '.'){
                    continue;
                }
                
                if(check[mat[row][col] - '1'] == 1){
                    return false;
                } else{
                    check[mat[row][col] - '1'] = true;
                }
            }
        }
        
        // check cols
        for(int col = 0; col < 9; col++){
            vector<bool> check(9,0);
            for(int row = 0; row < 9; row++){
                
                if(mat[row][col] == '.'){
                    continue;
                }
                
                if(check[mat[row][col] - '1'] == 1){
                    return false;
                } else{
                    check[mat[row][col] - '1'] = true;
                }
            }
        }
        
        //check boxes
        for(int startRow = 0; startRow < 9; startRow += 3){
            for(int startCol = 0; startCol < 9; startCol += 3){
                
                int r = startRow;
                int c = startCol;
                vector<bool> check(9,0); 
                while( r < startRow+3){
                    
                    if(mat[r][c] != '.'){
                        if(check[mat[r][c] - '1'] == 1){
                            return false;
                        } else {
                            check[mat[r][c] - '1'] = true;
                        }
                    }
                    
                    if(c < startCol+2){
                        c++;
                    } else{
                        c = startCol;
                        r++;
                    }
                    
                }
                
                
            }
        }
        
        
        return true;
        
    }
};
