// even more elegant solution by yours truly with less memory

bool isValidSudoku(vector<vector<char>>& mat) {
        
        // store the numbers encounterd till now
        vector<vector<int>> check(9);
        
        for(int i = 0; i < mat.size()*mat[0].size(); i++){
            
            // if empty continue
            if(mat[i/mat[0].size()][i%mat[0].size()] == '.'){
                continue;
            }
            
//             if none of this number have been found
            if(check[mat[i/mat[0].size()][i%mat[0].size()]-'0'-1].empty()){
                // store it - first encounter
                check[mat[i/mat[0].size()][i%mat[0].size()]-'0'-1].push_back(i);
            } else{
                // second encouter
                // check the list of previously encoutered for the same number
                for(int indx : check[mat[i/mat[0].size()][i%mat[0].size()]-'0'-1]){
                    // check if clashing rows
                    // clashing cols
                    // clashing blocks
                    if(indx%mat[0].size() == i%mat[0].size() || i/mat[0].size() == indx/mat[0].size() || ((i/(mat[0].size()*3))*3 +(i%(mat[0].size()))/3) == ((indx/(mat[0].size()*3))*3 +(indx%(mat[0].size()))/3)    ){
                        // if yes return false
                        return false;
                    }
                }
                // otherwise store it 
                check[mat[i/mat[0].size()][i%mat[0].size()]-'0'-1].push_back(i);
                
            }
        }
        
    // if no clashes return true
        return true;
    }

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
