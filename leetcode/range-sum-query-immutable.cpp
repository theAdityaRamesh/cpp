class NumArray {
public:
    NumArray(vector<int>& nums) {
        arr = nums;
        cumm = nums;
        // store the cummulative sums
        // since the sumRange will be called many times
        for(int i = 1; i < cumm.size(); i++){
            cumm[i] += cumm[i-1];
        }
    }
    
    int sumRange(int left, int right) {
        
        if(left == 0){
            return cumm[right];
        }
        return cumm[right]-cumm[left-1];
    }
private:
    vector<int> arr;
    vector<int> cumm;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
