class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        // subset[i+1] = subset[i] + num
        // so subsets can be of size 0,1,2 ... N
        // where N is the size of nums
        vector<vector<int>> res; // result 
        res.push_back({}); // push the empty subset
        stack<pair<int,vector<int>>> subs; // create a stack to create subsets
        // recursively
        int size = nums.size();
        int cnt = 0;
        // first push all the size 1 subsets into the stack
        // we use a ptr variable to get the index of that node in nums
        // we are calculating subsets
        // by 1, 2, 3, ...
        // 1,2 1,3 .... subsets starting with 1 of size 2
        // 2,3 2,4 ... subsets starting with 2 of size 2 and so on
        for(int i : nums){
            subs.push({cnt,{i}});
            cnt++;
        }
        
        
        while(!subs.empty()){
            // get the pos in nums
            int ptr = get<0>(subs.top());
            vector<int> top = get<1>(subs.top()); // get the current subset
            subs.pop(); // remove it from the stack
            
            if(ptr == size){ // if we reach the end of the nums 
                // just push the subset no need to go further
                res.push_back(top);
            } else{// otherwise push the current subset of size n-1
                // then iterate from the ptr+1 till end and add 1 value to make
                // subsets of size n
                res.push_back(top);
                for(int i = ptr+1; i < size; i++){
                    // push the subset of size n
                    // along with the ptr
                    // the ptr will be the index of the last element
                    // added
                    top.push_back(nums[i]);
                    subs.push({i, top});
                    top.pop_back();
                    // we remove it after adding
                    // as we will add other elements
                    
                }
            }
        }
        
        return res;
    }
};
