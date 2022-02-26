class Solution {
public:
    double average(vector<int>& salary) {
        
        int size;
        int minSal = INT_MAX;
        int maxSal = INT_MIN;
        int sum = 0;
        
        for(int s : salary){
            sum += s;
            minSal = min(s, minSal);
            maxSal = max(s, maxSal);
            size++;
        }
        
        // typecast to double before division
        // as ans is asking for ans within 10^-5 of actual ans
        // the salaries and size are in int
        // so int division will happen
        return (double(sum - minSal - maxSal)/double(size-2));
        
    }
};
