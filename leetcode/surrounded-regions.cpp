class Solution {
public:
    
    void flip(vector<vector<char>>& board, int r, int c){
        
        char label = 'X'; // initially assume that we can flip the O to X
        int rSize = board.size();
        int cSize = board[0].size();
        vector<pair<int,int>> nodes;
        stack<pair<int,int>> grid; // allocate a stack with the index
        grid.push({r, c}); // push the index where O was found
        
        while(!grid.empty()){
            r = get<0>(grid.top()); // get the row
            c = get<1>(grid.top()); // get the col
            grid.pop();// remove the current instance from stack
            board[r][c] = '1'; // mark as visited
            nodes.push_back({r,c});// add the curr node to the visited vector
            
            if(r == 0 || r == rSize-1 || c == 0 || c == cSize-1){
                label = '2'; // if while doing DFS we find a O on the border 
            } // change the label to 2
            
            // check the neighbours for O and push them into the stack
            
            //r-1, c
            if(r-1 > -1 && board[r-1][c] == 'O'){
                grid.push({r-1,c});
            }            
            //r+1, c
            if(r+1 < rSize && board[r+1][c] == 'O'){
                grid.push({r+1,c});
            } 
            //r, c+1
            if(c+1 < cSize && board[r][c+1] == 'O'){
                grid.push({r,c+1});
            } 
            //r, c-1
            if(c-1 > -1 && board[r][c-1] == 'O'){
                grid.push({r,c-1});
            } 
        }
        
        
        // after we finish marking all the neighbours
        // if the label is 2 then we mark it as 2
        // 2 means that O on the border has been found
        // we are using 1 to mark the areas which dont have a O on the border
        if(label == '2'){
            for(int i = 0; i < nodes.size(); i++){
                board[get<0>(nodes[i])][get<1>(nodes[i])] = '2';
            }
        }
    }
    
    void solve(vector<vector<char>>& board) {
        
        // in all cases the O can be flipped except
        // if we get a node that is on the border
        // that is the only way when we cant flip it
        
        int rSize = board.size(); // get the row size
        int cSize = board[0].size(); // get the col size
        // scan the entire board 
        for(int r = 0; r < rSize; r++){
            for(int c = 0; c < cSize; c++){
                // if we find a O flip the neighbours
                if(board[r][c] == 'O'){
                    flip(board, r, c);
                }
            }
        }     
        
        // after marking all the O
        // scan the board again
        // flip the O marked as 1 to X
        // as it they are valid
        // the other O marked as 2 have an connected
        // O in the border so mark them as O
        // we dont do it in the flip function because 
        // it will cause a loop while searching
        for(int r = 0; r < rSize; r++){
            for(int c = 0; c < cSize; c++){
                if(board[r][c] == '2'){
                    board[r][c] = 'O';
                } else{
                    board[r][c] = 'X';
                }
            }
        }
    }
};
