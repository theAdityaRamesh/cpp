class Solution {
public:
    int jump(vector<int>& nums) {
        
        int last = nums.size()-1,
            jump = 0,
            indx = 0,
            score = 0,
            min_score = last,
            jump_indx = 0;

        if(nums.size() == 1 || nums[0] == 0){
            return 0;
        } 
        
        while(indx < last){
            if(nums[indx] >= last){
                jump++;
                return jump;
            } else {                 
                for(int i = indx+1;i <=indx +nums[indx];i++){
                    score = last - (i+nums[i]);
                    
                    if(score <= 0){
                        jump += 2;
                        return jump;
                    } 
                    
                    if(score < min_score){
                        min_score = score;
                        jump_indx = i;
                    }
                }
                    min_score = last;    
                    indx = jump_indx;
                    jump++;
            }
        }
        
        return jump;
        
    }
};
