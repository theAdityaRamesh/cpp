class Solution {
public:
    
    int indx(int row, int glass){
        // at the ith row
        // ther will be i(i+1)/2 glasses before it
        // so add that
        // then add the glass indx
        return (row)*(row+1)/2 + (glass);
    }
    
    double champagneTower(int poured, int query_row, int query_glass) {
        
        // linearize the glass tower
        vector<double> tower(5050,0);
        // pour all the wine in the first glass
        tower[0] = poured; 
        int zero;
        
        
        for(int row = 0; row < 100; row++){   
            zero = 0;
            for(int glass = 0; glass <= row; glass++){
                // then move to the tower
                // and overflow the wine to the next row if its > 1
                // the i,j glass affects the i+1,j and i+1,j+1 glasses
                // before each row is completed the next row is filled
                if(tower[indx(row,glass)] > 1.0){
                    double quantity = tower[indx(row,glass)];
                    tower[indx(row, glass)] = 1;
                    if( row < 99){
                        tower[indx(row+1, glass)] += (quantity-1)/2;
                        tower[indx(row+1, glass+1)] += (quantity-1)/2;
                    }
                } else{
                    zero++;
                }
            } 
            
            // if for entire row all the glasses are below full
            // break
            if(row > 0 && zero == row){
                break;
            }
        }
         
        
        return tower[indx(query_row, query_glass)];
    }
};
