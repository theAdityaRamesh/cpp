class Solution {
public:
    int arraySign(vector<int>& nums) {
        
        int ans = 1;
        for(int i : nums){
            if(i == 0){
                // if we find a zero
                // ans is zero
                return 0;
            }
            // making all nums 1/-1 to avoid overflow
            ans *= abs(i)/i;
        }
        
        return ans;
    }
};
