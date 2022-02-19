// nums1 has space for nums2 at the end
// insert nums2 at the end of nums1
// insertion sort nums2 into nums1

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        if(m == 0){
            nums1 = nums2;
            return;
        }
        
        if(n == 0){
            return;
        }
        
        for(int i = m; i < nums1.size(); i++){
            nums1[i] = nums2[i-m];
        }
        
        int left = -1;
        int right = m;
        
        while(right < nums1.size()){
            int start = right;
            if(nums1[start] < nums1[start-1]){
                while(start > 0 && nums1[start-1] > nums1[start]){
                    swap(nums1[start-1], nums1[start]);
                    start--;
                }
            } right++;
                left++;
        }
        
    }
};
