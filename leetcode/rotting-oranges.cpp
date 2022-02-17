class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        int rowSize = grid.size();
        int colSize = grid[0].size();
        int numFresh = 0;
        int numRotten = 0;
        queue<pair<int,int>> track;
        
        for(int r = 0 ; r < rowSize ; r++){
            for(int c = 0; c < colSize; c++ ){
                if(grid[r][c] == 2){
                    numRotten++;
                    track.push(make_pair(r, c));
                } else if(grid[r][c] == 1){
                    numFresh++;
                }
                
            }
        }
        
        if(numFresh == 0){
            return 0;
        }
        
        int total = numRotten + numFresh;
        int prev = numRotten; // initial rotten oranges
        int orange = 0; // total rotten oranges
        int r,c;
        int min = 0;
                    
        while(!track.empty()){ // 1 min // 1 rot cycle            
            r = track.front().first;
            c = track.front().second;
            track.pop();
            orange++; // increase rotten oranges by one 
            // every time we check the front of Q 
            numRotten--; // decrease newly rotten oranges by 1
            // to keep track of rot cycle

            // check neighbours of rotten oranges
            // if we find a fresh orange rot it
            // decrease number of fresh oranges
            if(r > 0){
                if(grid[r-1][c] == 1 ){
                    numFresh--;
                    grid[r-1][c] = 2;
                    track.push(make_pair(r-1, c));
                }
            }

            if(r < rowSize-1){
                if(grid[r+1][c] == 1){
                    numFresh--;
                    grid[r+1][c] = 2;
                    track.push(make_pair(r+1, c));
                }
            }

            if(c > 0){
                if(grid[r][c-1] == 1){
                    grid[r][c-1] = 2;
                    numFresh--;
                    track.push(make_pair(r, c-1));
                }
            }

            if(c < colSize-1){
                if(grid[r][c+1] == 1){
                    grid[r][c+1] = 2;
                    numFresh--;
                    track.push(make_pair(r, c+1));
                }
            }                

            if(numRotten == 0){ // if newly rotten oranges have been checked
                min++; // increase time
                numRotten = total - prev - numFresh; // newly rotten oranges
                // is total oranges - prev rotten oranges - fresh oranges left
                prev += numRotten; // update total rotten oranges
            }

        }            
        
        if(orange != total){
            return -1; // if totally rotten oranges is not equal to total oranges
            // it means there is a unreacheable fresh orange
            // hece return -1
        }
            
            
        return min-1;
    }
        
};
