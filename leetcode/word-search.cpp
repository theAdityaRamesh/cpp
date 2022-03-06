class Solution {
public:
    
    bool check(vector<vector<char>>& board, const string& word, int r, int c, int indx){
       
        // recursively explire the neighbourhood of the pos where the first letter is found
        // in each call update the index which keeps track of which letter of the search string we
        // are searching
        
        // if the row col is out of bounds
        // return  false
       if(r < 0 || c < 0 || r >= board.size() || c >= board[0].size()){
           return false;
       }
        
       // if the current pos is visited
        // or if its not equal to the letter we are searching
        // return false for this direction
       if( board[r][c] == '#' || board[r][c] != word[indx]){
           return false;
       } 
        
       // if we reach teh last index
        // means we found the ans
        // if it was not equal to the correct letter it would have been rejected
        // in the prev step
       if(indx == word.size()-1){
           return true;
       }  
       
        // clever trick
        // store the current value of the board
       char curr = board[r][c];
        // as we are doing DFS
        // mark the current pos as visited
       board[r][c] = '#'; 
        // explore all 4 directions
        // if all 4 are false then we have to continue searching in ther main function
        // otherwise we return true as we have found the word
       bool ans = check(board, word, r+1, c, indx+1)||check(board, word, r-1, c, indx+1)||check(board, word, r, c+1, indx+1)||check(board, word, r, c-1, indx+1);
       board[r][c] = curr; // while going back // unrolling the stack restore the board pos to its correct value
        // this way we avoid maintaining a visited queue
       return ans;   
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        
        // we apply DFS here
        // scan the entire board to find the first letter of the word
        for(int r = 0; r < board.size(); r++){
            for(int c = 0; c < board[0].size(); c++){
                if(board[r][c] == word[0]){
                    // if the word exists return true as only 1 word has to be checked
                    if(check(board, word, r, c, 0)){
                        return true;
                    } 
                }
            }
        }
        
        
        return false;
        
    }
};
