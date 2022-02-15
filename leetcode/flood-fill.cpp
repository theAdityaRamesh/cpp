

class Solution {
public:
    
    void fill( vector<vector<int>>& image,int sr, int sc, int newColor) {
           
        
        if( 0 <= sr && sr < rowSize && sc >= 0 && sc < colSize){ // check if current pos in bounds
            if(image[sr][sc] == oldColor){ // if already painted return
                
                image[sr][sc] = newColor; // else paint
               
                // again call above and below curr pos recursively
                fill( image, sr, sc-1, newColor);
                fill( image, sr, sc+1, newColor);
                fill( image, sr+1, sc, newColor);
                fill( image, sr-1, sc, newColor);
            }
        } 
               
        return;
        
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        
        rowSize = image.size(); // get # of rwos
        colSize = image[0].size(); // get # of cols
        oldColor = image[sr][sc]; // get old color
        image[sr][sc] = newColor; // fill new color in starting pos
        
        if( newColor == oldColor){
            return image; // if old and new colors are same
        } // image is unchanged return
        
        // call fill function above and below the starting pos
      
        fill( image, sr, sc-1, newColor);
        fill( image, sr, sc+1, newColor);
        fill( image, sr+1, sc, newColor);
        fill( image, sr-1, sc, newColor);
        
        return image;
    }
    
private:
        int oldColor;
        int rowSize;
        int colSize;

};
