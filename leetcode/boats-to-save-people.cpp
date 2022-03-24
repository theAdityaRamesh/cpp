class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        
        // var to hold ans
        int boats = 0;
        // sort the people by weight
        sort(people.begin(), people.end());
        
        // left ptr at min element
        int left = 0;
        // right ptr at max element
        int right = people.size()-1;
        
        // scan till we choose the entire array
        // we have 2 ptrs left and right beacause
        // the boat can hold max 2 people
        while(left <= right){
            
            // we choose the 2 extreme elements and check
            // if they both can be carried together
            if(people[left]+people[right] <= limit){
                // if yes then send them by the same boat
                left++;
                right--;
                // increase boats by one
                boats++;
            } else {
                // otherwise the heaviear person is so heavy 
                // that even with the least possible weight
                // he cannot travel together since the rest of the 
                // people are heaveier than the left person we
                // send the right alone and check if we get any less 
                // heavier person that can travel with left
                right--;
                boats++;
            }
            
            // after each iteratiosn
            // left gets heavier
            // right gets ligheter
            
        }
        
        return boats;
    }
};
