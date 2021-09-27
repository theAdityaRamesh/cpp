// https://leetcode.com/problems/two-sum/

#include<vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        unordered_map<int,int> N;
        vector<int> result;
        
        for(int i=0;i<nums.size();i++)
        {
            int temp = nums[i];
            if(N.count(target-temp))
            {
                result.push_back(i);
                result.push_back(N[target-temp]);
            }            
            
            else
            {
                N.insert({temp,i});
            }
        }    
        
        return result;
        
    }
};
