class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        
        // the number that is common across the dominoes
        int rotateNum = -1;
        
        // scan thru the dominoes
        for(int i = 1; i < tops.size(); i++){
            // get the number which is common across the dominoes
            if(tops[i] == bottoms[i]){
                // if both top and bottom are identical we have fount thr num
                rotateNum = tops[i];
                break;
            }
            
            // check the current top and the prev top and bottom
            if(tops[i] == tops[i-1] || tops[i] == bottoms[i-1]){
                rotateNum = tops[i];
            } else if(bottoms[i] == tops[i-1] || bottoms[i] == bottoms[i-1]){
            // otherwise check the curr bottom and the prev top and bottom
                rotateNum = bottoms[i];
            } else{
            // if both the above dont match it means we have ended up with a 
            // domino that does not share any nums with its prev dominoes
            // hence we cant make the values in top or bottom equal
                return -1;
            }            
        }
        
        // now check the number of flips for making
        // top same and bottom same
        int topAns = 0;
        int botAns = 0;
        for(int i = 0; i < tops.size(); i++){
            topAns += tops[i] != rotateNum;
            botAns += bottoms[i] != rotateNum;
            
            if(tops[i] != rotateNum && bottoms[i] != rotateNum){
                return -1;
            }
        }
        
        // return the min of the 2
        return min(topAns, botAns);
    }
    
};
