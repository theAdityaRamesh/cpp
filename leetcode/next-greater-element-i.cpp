class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        
        int size1 = nums1.size();
        int size2 = nums2.size();      
        // make vector of all next greatear to -1
        // so if we dont find a match it is by default -1
        vector<int> ans(size1, -1);
        // hashmap
        unordered_map<int,int> check;
        // stack to keep track of the elements encoutered till now
        stack<int> prev;
        
        // at each iteration
        // check the stack
        // if empty push the current element
        // otherwise
        // if current element is > TOS
        // pop elements from from the stack till the above cond is true
        // push the current element at the end of each iteration
        // store the matches in a hashMap
        for(int i = 0 ; i < size2; i++){
                while(!prev.empty() && nums2[i] > prev.top()){
                    check[prev.top()] = nums2[i];
                    prev.pop();   
                }
            
            prev.push(nums2[i]);
        }
        
        // in the query array
        // we check each query 
        // take the next greatear from the hashMap
        // update in the ans
        // if it DNE by default ans is -1
        for(int i = 0; i < size1; i++){
            if(check.find(nums1[i]) != check.end()){
                ans[i] = check[nums1[i]];
            }
        }
        
        return ans;
    }
};
