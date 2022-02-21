class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        
        int ir = mat.size();
        int ic = mat[0].size();
        
        if(r*c != ir*ic || (r == ir && c == ic)){
            return mat; // if dimensions < =original dimenstions
        }
        
        int cr = 0;
        int cc = 0;
        
        int rr = 0;
        int rc = 0;
        
        vector<vector<int>> reshape(r, vector<int>(c,0));
        
        // iterate thru og matrix and new matrix at same time
        while( cr < ir && cc < ic ){
            
            reshape[rr][rc] = mat[cr][cc];
            
            if(rc < c-1){
                rc++;
            } else {
                if(rr < r - 1){
                    rr++;
                    rc = 0;
                }
            }            
            
            if(cc < ic-1){
                cc++;
            } else{
                if(cr < ir-1){
                    cr++;
                    cc = 0;
                    cout << endl;
                } else {
                    cr++;
                }
            }
            
        }
        return reshape;
    }
};
