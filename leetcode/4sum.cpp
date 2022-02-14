// 4sum by generating all 2sum pairs

class Solution {
public:
    unordered_map<int,vector<pair<int,int>>> twoSum;
    set<vector<int>> fourS;
        
    
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
        for(int i = 0; i < nums.size(); i++){
            for(int j = i+1; j < nums.size(); j++){                
                twoSum[nums[i]+nums[j]].push_back({i,j});
            }
        }
        
        for(auto [key, value] : twoSum){
            
            int match = target - key;
            
            if(twoSum.find(match) != twoSum.end()){
                
                for(auto[a,b] : twoSum[key]){
                    for(auto[c,d] : twoSum[match]){
                        
                        if(a != c && a != d && b != c && b != d) {
                            vector<int> temp = { nums[c], nums[d], nums[a], nums[b]};
                            sort(temp.begin(), temp.end());
                            fourS.insert(temp);
                        }
                        
                    }
                }
                
            }
        }
        
        vector<vector<int>> res(fourS.begin(), fourS.end());
        return res;
    }    
    
};


// O(n^3) complexity recursive method
// generalized sum for k sums

class Solution {
public:
    
    vector<vector<int>> twoSum(const vector<int>& nums, const int& target, const int& curr){

        vector<vector<int>> res;
        int left = curr;
        int size = nums.size();
        int right = size - 1;
        
        while(left < right){
            
            int sum = nums[left] + nums[right];
            
            if (sum < target || (left > curr && nums[left] == nums[left - 1])) {
                ++left;
            } else if (sum > target || (right < size - 1 && nums[right] == nums[right + 1])) {
                --right;
            } 
            
            else {
                res.push_back({
                    nums[left],
                    nums[right]
                });
                
                left++;
                right--;                
            }
        }
    
        return res;
    }    

    vector<vector<int>> kSum(const vector<int>& nums, const int& target, const int& curr,  const int& k){
        
        vector<vector<int>> res;
        
        if(curr == nums.size()){
            return res; 
        }
        
        
        int avg = target/k;
        if( nums[curr] > avg || nums.back() < avg){
            return res;
        }
        
        if( k == 2){
            return twoSum(nums, target, curr);
        }
        
        for(int i = curr; i < nums.size(); i++){
            if(i == curr || nums[i-1] != nums[i]){

                for(vector<int>& subset : kSum(nums, target - nums[i], i + 1, k-1)){
                    res.push_back({nums[i]});
                    res.back().insert(res.back().end(), subset.begin(), subset.end());
                }
            
            }
        }
        
        return res;
        
    }
    
    vector<vector<int>> fourSum(vector<int>& nums, int target) {        
        sort(nums.begin(), nums.end());
        return kSum(nums, target, 0, 4);
    }
};

// O(n^3) complexity iterative method with 
// loop termination conditions

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
        int size = nums.size();
        
        sort(nums.begin(), nums.end());        
        vector<vector<int>> res;
        
        if(size < 4){
            return res;
        }

        
        for(int i = 0; i < size-3; i++){

            
            if( target < 0 && nums[i] >0){break;}
            if((long long) nums[i] + nums[i+1] + nums[i+2] + nums[i+3] > target){break;}
            if( (long long) nums[i] + nums[size-1] + nums[size-2]+nums[size-3] < target){continue;}
            if(i > 0 && nums[i] == nums[i-1]){continue;}
            
            for(int left = i+1; left < nums.size()-2; left++){
                
                if((long long) nums[i]+nums[left]+nums[left+1]+nums[left+2] > target){break;}
                if((long long) nums[i] + nums[left] + nums[size-1] + nums[size-2] < target){continue;}
                if(left > i+1 && nums[left] == nums[left-1]){continue;}

                int low = left+1;
                int high = size-1;
                
                while( low < high ){

                    int sum = nums[i] + nums[left] + nums[low] + nums[high];
                    if( sum  == target){
                        res.push_back({ nums[i], nums[left], nums[low], nums[high] });
                        
                        while( low < size-2 && nums[low] == nums[low+1]){ low++ ; }
                        while( high > 1 && nums[high] == nums[high-1]){ high--; }
                        
                        low++;
                        high--;
                        
                    } else {
                        low = sum < target ? low+1 : low;
                        high = sum > target ? high-1 : high;
                    }
                }
                
            }
            
        }
        
        return res;
    }
};


// O(n^3) complexity iterative method

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
        int size = nums.size();
        
        sort(nums.begin(), nums.end());        
        vector<vector<int>> res;
        
        if(size < 4){
            return res;
        }
        
        if(target >= 0 && nums[0] > target){
            return res;
        }
        
        if(target < 0 && nums[0] > 0){
            return res;
        }
        
        for(int i = 0; i < size; i++){
            
            if(i > 0 && nums[i] == nums[i-1]){
                continue;
            } 
            
            for(int left = i+1; left < nums.size(); left++){
                
                if(left > i+1 && nums[left] == nums[left-1]){
                    continue;
                }
                
                int low = left+1;
                int high = size-1;
                
                while( low < high ){
                    
                    if(nums[low] >= 1000000000 || nums[low] <= -1000000000){
                        break;
                    }
                    
                    int sum = nums[i] + nums[left] + nums[low] + nums[high];
                    if( sum  == target){
                        res.push_back({ nums[i], nums[left], nums[low], nums[high] });
                        
                        while( low < size-2 && nums[low] == nums[low+1]){ low++ ; }
                        while( high > 1 && nums[high] == nums[high-1]){ high--; }
                        
                        low++;
                        high--;
                        
                    } else {
                        low = sum < target ? low+1 : low;
                        high = sum > target ? high-1 : high;
                    }
                }
                
            }
            
        }
        
        return res;
    }
};
