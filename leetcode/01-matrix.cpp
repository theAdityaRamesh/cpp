class Solution {
public:
    
    int distance(int cr, int cc, int r, int c){
        return abs(cr-r) + abs(cc-c);
    }
    
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        
        int rowSize = mat.size();
        int colSize = mat[0].size();
        
        int cr = 0;
        int cc = 0;
        
        vector<vector<int>>  dist(rowSize, vector<int>(colSize, INT_MAX-1));
        queue<pair<int,int>> track;

        for(int i = 0; i < rowSize; i++){
            for(int j = 0; j < colSize; j++){
                if(mat[i][j] == 0){
                    track.push(make_pair(i,j)); // get all the zeros in the matrix
                    dist[i][j] = 0; // make their distances = 0
                }
            }
        }
        
        
        
        while(!track.empty()){ // while there are still nodes to be checked
            
            int r = track.front().first;
            int c = track.front().second;
            track.pop();// the the oldest in the Q
            
            // check the neighbours in all 4 directions
            // if the  distance to get to zero + 1 ( distance to get to neighbour) 
            // is less than the current distance to zero of the neighbour
            // update the neighbour and push the neighbour into Q
           // to check its neighbours
            if(r > 0){
                if(mat[r-1][c] != 0 && dist[r-1][c] > dist[r][c] + 1){
                    dist[r-1][c] = dist[r][c] + 1;
                    track.push(make_pair(r-1, c));
                }
            }
            
            if(r < rowSize-1){
                if(mat[r+1][c] != 0 && dist[r+1][c] > dist[r][c] + 1){
                    dist[r+1][c] = dist[r][c] + 1;
                    track.push(make_pair(r+1, c));
                }
            }
            
            if(c > 0){
                if(mat[r][c-1] != 0 && dist[r][c-1] > dist[r][c] + 1){
                    dist[r][c-1] = dist[r][c] + 1;
                    track.push(make_pair(r, c-1));
                }
            }
            
            if(c < colSize-1){
                if(mat[r][c+1] != 0 && dist[r][c+1] > dist[r][c] + 1){
                    dist[r][c+1] = dist[r][c] + 1;
                    track.push(make_pair(r, c+1));
                }
            }
            
        }
        
        return dist;
    }
};
