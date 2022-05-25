class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        
        // same code as spiral matrix 
        
        vector<vector<int>> matrix(n, vector<int>(n,0));
        // vector to keep track of visited indx
        vector<bool> visited(matrix.size()*matrix[0].size(),0);
        
        // visite the first node
        // mark it as visited
        // store it
        int curr = 0;
        visited[0] = true;
        matrix[0][0] = ++curr;
        // increment the curr index
        int indx = 0;
        
        // keep visiting the matrix till we have visited all the nodes
        while(curr < matrix.size()*matrix[0].size()){
            // travel row
            travel_row(matrix, visited, indx, curr);
            // travel col
            travel_col(matrix, visited, indx, curr);
        }
        
        return matrix;
    }
    
private:
    void travel_row(vector<vector<int>>& matrix, vector<bool>& visited, int& indx, int& curr){          
        
        int add ;
        // go right see if its not blocked
        if(indx+1 < visited.size() && !visited[indx+1]){
            add = 1;
        } else{
        // else go left
            add = -1;
        }
        
        int row = indx/matrix[0].size();
        row += add;
        indx += add;
        
        while(indx/matrix[0].size() != row && !visited[indx]){
            matrix[indx/matrix[0].size()][indx%matrix[0].size()] = curr++ + 1;
            visited[indx] = true;
            indx += add;
        }
        
        // come back into bounds
        indx -= add;
        
    }
    
    void travel_col(vector<vector<int>>& matrix, vector<bool>& visited, int& indx, int& curr){  

        int add ;
        // go down to see if its blocked
        if(indx+matrix[0].size() < visited.size() && !visited[indx+matrix[0].size()]){
            add = matrix[0].size();
        } else{
            // else go up
            add = -matrix[0].size();
        } 
        
        indx += add;
        
        while(indx/matrix[0].size() < matrix.size() && indx/matrix[0].size() >= 0 && !visited[indx]){
            matrix[indx/matrix[0].size()][indx%matrix[0].size()] = curr++ + 1;
            visited[indx] = true;
            indx += add;
        }
        
        // come back into bounds
        indx -= add;
    }
    
    
    
};
