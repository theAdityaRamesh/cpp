class Solution {
public:
    // check if pts satisfy y = mx + c
    bool checkStraightLine(vector<vector<int>>& pts) {
        
        int size = pts.size();
        int A = (pts[1][1] - pts[0][1]); // y2-y1
        int B = (pts[1][0] - pts[0][0]); // x2-x1
        int C, D;
        
        for(int i = 2; i < size; i++){
            C = (pts[i][1]-pts[i-1][1]); // Y - y1
            D = (pts[i][0]-pts[i-1][0]); // X - x1
            if(C*B - D*A != 0){
                return false;
            }
        }
        
        return true;
    }
};
