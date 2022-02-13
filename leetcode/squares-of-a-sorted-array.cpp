class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        
        if(nums.size() == 1){
            int temp = nums[0];
            nums.clear();
            nums.push_back(temp*temp);
            return nums;
        }
        
        int left = 0;
        int size = nums.size();
        int right = size-1;
        vector<int> result = nums;
        
        for(int i = size-1; i >= 0; i--){
            if(abs(nums[left]) > nums[right]){
                result[i] = nums[left]*nums[left++];
            } else {
                result[i] = nums[right]*nums[right--];
            }
        }
        
        return result;

    }
};
