class Solution {
public:
    
    void pushNeighbours(vector<vector<int>>& grid, queue<pair<pair<int,int>,int>>& travel ,int r, int c, int pathLen, int rSize, int cSize){
        
            // check each 8 directional neighbour for out of bounds
            // if within bounds
            // check if its unvisited or can be reached in a shorter path than it previously has
            // if either is true push it into the Q
        
            // r-1, c-1
            if(r-1 > -1 && c-1 > -1 && (grid[r-1][c-1] == 0 || grid[r-1][c-1] > grid[r][c]+1) ){
                travel.push({{r-1,c-1},pathLen+1});
            }

            // r-1, c
            if(r-1 > -1 && (grid[r-1][c] == 0 || grid[r-1][c] > grid[r][c]+1)){
                travel.push({{r-1,c},pathLen+1});
            }   

            // r-1, c+1
            if(r-1 > -1 && c+1 < cSize && (grid[r-1][c+1] == 0 || grid[r-1][c+1] > grid[r][c]+1)){
                travel.push({{r-1,c+1},pathLen+1});
            }

            // r, c-1
            if(c-1 > -1 && (grid[r][c-1] == 0 || grid[r][c-1] > grid[r][c]+1)){
                travel.push({{r,c-1},pathLen+1});
            }

             // r, c+1
            if(c+1 < cSize && (grid[r][c+1] == 0 || grid[r][c+1] > grid[r][c]+1)){
                travel.push({{r,c+1},pathLen+1});
            }

            // r+1, c-1
            if(r+1 < rSize && c-1 > -1 && (grid[r+1][c-1] == 0 || grid[r+1][c-1] > grid[r][c]+1)){
                travel.push({{r+1,c-1},pathLen+1});
            }

            // r+1, c
            if(r+1 < rSize && (grid[r+1][c] == 0 || grid[r+1][c] > grid[r][c]+1)){
                travel.push({{r+1,c},pathLen+1});
            }

             // r+1, c+1
            if(r+1 < rSize && c+1 < cSize && (grid[r+1][c+1] == 0 || grid[r+1][c+1] > grid[r][c]+1)){
                travel.push({{r+1,c+1},pathLen+1});
            }
                
               
    }
    
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        
        
        int rSize = grid.size(); // get row size
        int cSize = grid[0].size(); // get colSize
        
        //if top left or bottom right is unreachable
        if(grid[0][0] == 1 || grid[rSize-1][cSize-1] == 1){
            return -1;
        }
        
        // <row,col>,pathlen
        queue<pair<pair<int,int>,int>> travel;
        // since binary matrix
        // take initial pathlen as 2 to differentiate b/w 0/1
        travel.push({{0,0},2});
        
        while(!travel.empty()){
            // get row, col and pathlen
            int row = get<0>(get<0>(travel.front()));
            int col = get<1>(get<0>(travel.front()));
            int pathLen = get<1>(travel.front());
            travel.pop();
                        
            
            if(grid[row][col] == 0){
                // unvisited node
                grid[row][col] = pathLen; // update pathlen
                pushNeighbours(grid, travel, row, col, pathLen, rSize, cSize); // push nearby nodes
            } else if(grid[row][col] > pathLen){
                grid[row][col] = pathLen; // otherwise if we find shorter path update
                pushNeighbours(grid, travel, row, col, pathLen, rSize, cSize); // push nearby nodes
            }
        }   
    
        // if we did not reach the end node it will be zero
        if(grid[rSize-1][cSize-1] == 0){
            return -1;
        } else{
            // since we took pathlen as 2 initially sub 1
            return grid[rSize-1][cSize-1]-1;
        }
    }
};
