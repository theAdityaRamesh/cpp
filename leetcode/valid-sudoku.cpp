// more elegant solution 
// need to traverse matrix only once

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& mat) {
        
        vector<vector<bool>> colCheck(9, vector<bool>(9, 0));
        vector<vector<bool>> blockCheck(9, vector<bool>(9, 0));
        
        for(int row = 0; row < 9; row++){
            vector<bool> rowCheck(9,0);
            for(int col = 0; col < 9; col++){
                if(mat[row][col] == '.'){
                    continue;
                } 
                
                int num = (mat[row][col] - '1');
                int blockIndx = 3*(row/3) + (col/3);
                if( rowCheck[num] || colCheck[num][col] || blockCheck[blockIndx][num]){
                    return false;
                } else {
                    rowCheck[num] = true;
                    colCheck[num][col] = true;
                    blockCheck[blockIndx][num] = true;
                }
            }
        }
        
        
        return true;
        
    }
};




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
