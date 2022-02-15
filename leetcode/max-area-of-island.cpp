class Solution {
public:
    
    void getArea(vector<vector<int>>& grid, int &cnt, int sr, int sc){
        
        if( sr < 0 || sr >= rowSize || sc < 0 || sc >= colSize) {
            return ; // out of bounds return
        }
                
        if(grid[sr][sc] == -2 || grid[sr][sc] == -1){
            return; // already visted return
        }
        
        if(grid[sr][sc] == 0){
            grid[sr][sc] = -2; // mark as visted by getArea
            return;
        } 
        
        // if grid[sr][sc] == 1 
        // only option left
        // explore the area
        
        grid[sr][sc] = -2; // mark as visited by getArea
        cnt++; // increase beacause 1 found
        
        if(sc > 0 && grid[sr][sc-1] == 1){
            getArea(grid, cnt, sr, sc-1);
        }
        
        if(sc < colSize-1 && grid[sr][sc+1] == 1){
            getArea(grid, cnt, sr, sc+1);
        }
        
        if(sr > 0 && grid[sr-1][sc] == 1){
            getArea(grid, cnt, sr-1, sc);
        }
        
        if(sr < rowSize-1 && grid[sr+1][sc] == 1){
            getArea(grid, cnt, sr+1, sc);
        } 
        

        return;       
        
    }
    
    void crawl(vector<vector<int>>& grid, int& cnt, int sr, int sc){
        
        if( sr < 0 || sr >= rowSize || sc < 0 || sc >= colSize) {
            return; // if out of bounds return
        }            

        if(grid[sr][sc] == -1){
            return; // if already visited return
        } 

        if( grid[sr][sc] == 1){ // if 1 found
            int cnt1 = 0; // because one 1 found
            getArea(grid, cnt1, sr, sc);
            cnt = cnt1 > cnt ? cnt1 : cnt; // if greatear than max 
        } // upadte
        
        // function come till here if either 
        // grid[sr][sc] = 1 / 0 / -2 (visted by getArea but not by crawl)
      
        grid[sr][sc] = -1; // mark as visited
        
        if(sc > 0 && grid[sr][sc-1] != -1){
            crawl(grid, cnt, sr, sc-1);
        }
        
        if(sc < colSize-1 && grid[sr][sc+1] != -1){
            crawl(grid, cnt, sr, sc+1);
        }
        
        if(sr > 0 && grid[sr-1][sc] != -1){
            crawl(grid, cnt, sr-1, sc);
        }
        
        if(sr < rowSize-1 && grid[sr+1][sc] != -1){
            crawl(grid, cnt, sr+1, sc);
        } 
        
        
        return;        
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        
        int cnt = 0;
        rowSize = grid.size();
        colSize = grid[0].size();
        crawl(grid, cnt, 0, 0);
        
        return cnt;
        
    }
    
private:
    int rowSize;
    int colSize;
};
