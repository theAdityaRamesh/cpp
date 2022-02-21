class Solution {
public:
    
    int majorityElement(vector<int>& nums) {
        int size = nums.size();
        int majSize = size/2;

        sort(nums.begin(), nums.end());
        
        for(int i = 1; i < size; i++){
            
            if(majSize <= 0){
                return nums[i-1];
            }
            
            if(nums[i] == nums[i-1]){
                majSize--;
            } else {
                majSize = size/2;
            }
        }        
    
        
        return nums.back();
    }
    
// since according to the question
// the majority element exists more than floor(n/2) times
// it means atleast 1 more than half # of times it occurs
// so rest of the elements occur n/2 - 1 time in the worst case
// so if we cancel out each majority element
// with non majority element 
// then all that remains is the majority element
int majorityElement(vector<int> &num) {
    int majorityIndex = 0; 
    int maj = num[0] ;
    for (int count = 1, i = 1; i < num.size(); i++) {
        maj == num[i] ? count++ : count--;
        if (count == 0) {
            maj = num[i];
            count = 1;
        }
    }
        
    return maj;
}
    
};
