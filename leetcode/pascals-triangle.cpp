class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        
        vector<vector<int>> res;
        if(numRows == 1){
            res.push_back({1});
            return res;
        }
        
        res.push_back({1});
        res.push_back({1,1});
        int row = 3;
        while(row <= numRows){
            vector<int> roww(row,1);
            int col = 1;
            while(col < row-1){
                roww[col] = res[row-2][col] + res[row-2][col-1];
                col++;
            } res.push_back(roww); row++;
        }
    
        return res;
    }
};
