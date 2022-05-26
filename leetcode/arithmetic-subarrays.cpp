class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        
        
        vector<bool> ans(l.size(), true);
        for(int i = 0; i < l.size(); i++){
            
            // if we have 1/0 elements then no points in checking
            if(r[i]-l[i] <= 1){
                ans[i] = true;
                continue;
            } else {            
                // check the array
                ans[i] = insert_and_check(nums, l[i], r[i]);
            }
        }
        
        return ans;
    }
    
private:
    
    bool insert_and_check(vector<int>& nums, int left, int right){

        // in order to find if a sequence is a AP
        // we can sort the entire sequence and check the difference
        // however this is very ineeficient
        // O(n*m*logm) where n is the size of the larger arraty
        // m is the size of the smaller array
        
        // a better approach is to use properties of AP
        // a, a+d, a+2d ... a+(n-1)d
        // scam the small array find the max and min ele
        // get the common difference
        // a+(n-1)d - a / (n-1)
        // we can then use a bool array to check for repititions
        // and scan the small array adn find the poistion of each element in the sequence
        
        
        if(right-left <= 1){
            return true;
        }
        
        int min_ele = nums[left];
        int max_ele = nums[left];
        
        for(int i = left; i <= right; i++){
            min_ele = min(min_ele, nums[i]);
            max_ele = max(max_ele, nums[i]);
        }
        
        if((max_ele - min_ele)%(right-left)){
            return false;
        }
        
        int d = (max_ele - min_ele)/(right-left);
        vector<bool> check(right-left+1, false);
        
        // if min and max are same it means its and AP with d=0
        // we cant divide by 0
        // so we check all the elements are equal
        // if yes return true
        // or retuyrn false
        if(min_ele == max_ele){
            for(int i = left; i <= right; i++){
                if(nums[i] != min_ele){
                    return false;
                }
            }
            
            return true;
        }
        
        for(int i = left; i <= right; i++){
            if(check[(nums[i]-min_ele)/d] || (nums[i]-min_ele)%d != 0 ){
                return false;
            } else{
                check[(nums[i]-min_ele)/d] = true;
            }
        }
                
        return true;
    }
    
};
