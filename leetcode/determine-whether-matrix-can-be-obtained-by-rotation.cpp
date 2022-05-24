class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        
        bool result;
        
        // since after 3 rotations matrix will be restored to its
        // original state
        for(int i = 0 ; i < 4; i++){
            // for each rotation we compare the rows
            // one by one between the original matrix & 
            // the rotated matrix.
            result = true;
            // cout << i << endl;
            for(int row = 0; row < mat.size(); row++){
                result = compareRow(mat, target, row, i);
                // if we find that a row does not match
                // break and check the next rotation.
                if(result == false){
                    break;
                }
            }
            // if after a particular rotation we still have
            // all values same
            // stop searching return true;
            if(result){
                break;
            }
        }
        
        return result;
    }
    
private:
    
    bool compareRow(const vector<vector<int>>& mat, const vector<vector<int>>& target, int row, int rotation){
        
        // we compare the matrices row by row 
        // using the orignial matrix and the target matrix after rotation
        // ie we take the orignial index roatate it
        // then use the rotated index in the target matrix
        pair<int,int> og;
        pair<int,int> rt;
        og.first = row;
        
        for(int i = 0; i < mat.size(); i++){
            // iterating over columns for the fixed row in function arg
            og.second = i;
            // get the rotate index
            performRotation(og,rt, rotation, mat.size());
            // if we find a mismatch we return false imeediately
            if(mat[og.first][og.second] != target[rt.first][rt.second]){
                return false;
            }
        }
                
        return true;
    }
    
    
    void performRotation(const pair<int,int>& og, pair<int,int>& rt, int rotation, int N){
        
        // dont rotate
        if(rotation == 0){
            rt = og;
        } else if(rotation == 1){
            rt = rotate(og, N); // rotate once
        } else if(rotation == 2){
            rt = rotate(rotate(og, N), N); // rotate twice
        } else if(rotation == 3){
            rt = rotate(rotate(rotate(og, N), N), N); // rotate thrice
        } // 4 times rotation is the original matrix itseld
    }
    
    // helper function to get rotated index
    pair<int,int> rotate(const pair<int,int>& indx, int N){
        return {indx.second, N-1-indx.first};
    }
    
};
