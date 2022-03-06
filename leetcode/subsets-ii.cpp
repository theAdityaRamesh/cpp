class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        
        // pretty much same approach as subsets withot duplicates
        // but we sort the array first to get all the duplicates together
        // while going from size n to size n+1
        // we take the first instance og the duplicate and skip the rest
        // to avoid duplicate subsets
        
        sort(nums.begin(), nums.end());
        
        vector<vector<int>> res;
        res.push_back({});
        stack<pair<int,vector<int>>> subs;
        int size = nums.size();
        int cnt = 0;
        subs.push({0, {nums[0]}});
        
        for(int i = 1; i < size; i++){
            if(nums[i] == nums[i-1]){
                continue;
            }
            subs.push({i, {nums[i]}});
        }
        
        while(!subs.empty()){
            int ptr = get<0>(subs.top());
            vector<int> top = get<1>(subs.top());
            subs.pop();
            
            if(ptr == size){
                res.push_back(top);
            } else{
                
                res.push_back(top);
                // here we take the first instance of the duplicate
                // and push it
                if(ptr+1 < size){
                    top.push_back(nums[ptr+1]);
                    subs.push({ptr+1, top});
                    top.pop_back();
                }
                for(int i = ptr+2; i < size; i++){
                    // after that from ptr+2 we check and skip all the duplicates
                    if(nums[i] == nums[i-1]){
                        continue;
                    }
                    top.push_back(nums[i]);
                    subs.push({i, top});
                    top.pop_back();
                }
            }
        }
        
        return res;
        
        
    }
};
