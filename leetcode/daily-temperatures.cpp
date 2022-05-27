class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        
        // approach 1 is to use a stack
        // and keep stacking the temperatures till
        // we get a warm day compared to the prev day
        // then go backwards till the temperature is colder 
        // than the curr day
        // THis is slighlty problamatic when we lots of colder days
        // followed by a warm day
        
        // we can instead skip days using the ans vector as we know
        // after hoe many days the curr day will have a warm day
        
        // iterate thru the days backwards
        // record the max temp encounterd yet
        int max_temp = temperatures.size()-1;
        vector<int> ans(temperatures.size(), 0);
        
        for(int i = temperatures.size()-1; i >= 0; i--){
            // if we encounter a temp hotter than all the temp after it in the array
            // then we record it as max temp and move on
            if(temperatures[i] >= temperatures[max_temp]){
                max_temp = i;
                continue;
            } 
            
            // else we skip the array starting with
            // the next index using the ans array
            // we are guarenteed to have an ans becaseu
            // the current temp is less than the hottest temp
            // encounterd yet
            // hence either the next index is the hottest
            // or its not the hottest and hence has a warmer day ahead
            int days = 1+i;
            int curr_temp = temperatures[i];
            while(temperatures[days] <= curr_temp){
                days += ans[days];
            } ans[i] = days-i;
        }
        
        return ans;        
    }
};
