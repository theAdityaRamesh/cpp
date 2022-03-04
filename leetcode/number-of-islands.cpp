class Solution {
public: 
    
    void visitIsland(vector<vector<char>>& grid, int row, int col, int rSize, int cSize){
        
        if(grid[row][col] == '1'){
            grid[row][col] = '#';
            
            if(row+1 < rSize && grid[row+1][col] == '1'){
                visitIsland(grid, row+1, col, rSize, cSize);
            }
            
            if(row-1 > -1 && grid[row-1][col] == '1'){
                visitIsland(grid, row-1, col, rSize, cSize);
            }
            
            if(col+1 < cSize && grid[row][col+1] == '1'){
                visitIsland(grid, row, col+1, rSize, cSize);
            }
            
            if(col-1 > -1 && grid[row][col-1] == '1'){
                visitIsland(grid, row, col-1, rSize, cSize);
            }
        }
        
        return;
    }
    
    int numIslands(vector<vector<char>>& grid) {
        
        // ans is num islands
        int ans = 0;
        int rSize = grid.size();
        int cSize = grid[0].size();
        
        // iterate thru the grid using 2 loops
        for(int row = 0 ; row < rSize; row++){
            for(int col = 0; col < cSize; col++){
                if(grid[row][col] == '1'){
                    // whenver we find a land
                    // visit the entire island
                    ans++;
                    visitIsland(grid, row, col, rSize, cSize);
                } // skip 0 and visited places
            }
        }
        
        return ans;
    }
};
