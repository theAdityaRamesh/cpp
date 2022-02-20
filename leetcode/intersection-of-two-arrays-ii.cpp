class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        
        // M1 using sorting
        
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        
        int p1 = 0;
        int p2 = 0;
        vector<int> res;
        
        while(p1 < nums1.size() && p2 < nums2.size()){
            
            if(nums1[p1] < nums2[p2]){
                p1++;
            } else if(nums1[p1] > nums2[p2]){
                p2++;
            } else{
                if(nums1[p1] == nums2[p2]){
                    res.push_back(nums1[p1]);
                    p1++;
                    p2++;
                }
            }
        }
        
        // M2 using hash map
        
        unordered_map<int,int> intersect;
        for(int i = 0; i < nums1.size(); i++){
            intersect[nums1[i]]++;
        } // hash all entries of the first map
     // key = number
      // value = frequency
        vector<int> res;
        // iterate thru second array
        for(int i = 0; i < nums2.size(); i++){
            if(intersect.find(nums2[i]) != intersect.end()){
                if(intersect[nums2[i]] != 0){
                    res.push_back(nums2[i]); // if we find a match and freq != 0 decrease frequ push into result
                    intersect[nums2[i]]--;
                } 
            }
        }
        
        return res;
        
    }
};
