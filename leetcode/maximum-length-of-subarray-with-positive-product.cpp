class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        
        int size = nums.size();
        
        if(size == 1){
            return nums[0] > 0;
        }
        
        // keeps track of +ve product
        int maxProd;
        // keeps track of max +ve product len
        int maxLen;
        // keeps track of max -ve product 
        int minProd;
        // keeps track of max -ve product len
        int minLen;
        // ans 
        int ans = 0;
        
        
        if(nums[0] > 0){
            // if first element is +ve
            maxProd = 1; // +ve prod is 1
            minProd = 0;// -ve prod is 0
            maxLen = 1;// +ve len is 1
            minLen = 0;// -ve len is 0
        } else if(nums[0] < 0){
            // if first element is -ve
            maxProd = -1; // +ve product - ve
            minProd = -1;// -ve product -ve
            maxLen = 0; // +ve len is 0
            minLen = 1;// -ve len is 1
        }  else {
            // is first element is 0
            // all are 0
            maxProd = 0;
            maxLen = 0;
            minProd = 0;
            minLen = 0;
        }
        
        for(int i = 1; i < size; i++){
            
            // if ith element is zero
            // reset all the counts
            // as subarray cannot continue
            // and go to next index
            if(nums[i] == 0){
                maxLen = 0;
                minLen = 0;
                maxProd = 0;
                minProd = 0;
                continue;
            }
            
            // if ith element is +ve
            if(nums[i] > 0){
                // used for starting cond
                // or reset after a zero element
                // at start if first element is 1
                // +ve prodcut is set to -1
                if(maxProd == -1){
                    // we have reachead a +ve number @ i
                    // so maxProd is +ve now
                    maxProd = 1;
                    // maxLen is 1
                    // we start counting from i
                    maxLen = 1;
                } else {
                    // if +ve prod is already +Ve
                    // increment by one
                    // as one more +ve number found
                    maxLen++;
                }
                // if -ve product is +ve
                // for starting cond
                // or for reset after zero
                if(minProd != -1){
                    // set -ve prod to zero
                    // as curr element is +ve
                    minProd = 0;
                    // set -ve len to zero
                    minLen = 0;
                } else {
                    // if -ve product is -ve
                    // -ve * +ve = -ve
                    // so increment -ve len by 1
                    minLen++;
                }
            }
            
            if(nums[i] < 0){
                
                // store current state of -ve prod
                // as we will be changing it
                int temp = minProd;
                int tempLen = minLen;
                
                // if +ve product is not -ve or zero
                if(maxProd != -1){
                    // set -ve product to -ve
                    minProd = -1;
                    // set -ve len to +ve len +1
                    // as we cant use -ve prod len as current
                    // element is -ve
                    minLen = maxLen+1;
                } else {
                    // if +veprod is not +ve
                    // ie -ve or zero
                    // we start fresh
                    // from current -ve element
                    minProd = -1;
                    minLen = 1;
                }
                
                // since we changed the -ve prod values
                // using temp variable
                if(temp == -1){ // check -ve product
                    // if its not +ve or zero
                    // we cant use +ve prod values
                    // as current is -ve element
                    maxProd = 1;
                    // set +ve product to +ve
                    maxLen = tempLen+1;
                    // set +ve product len to -ve prod + 1
                } else{
                    // other wise
                    // if -ve product is +ve
                    // reset +ve prod values as
                    // we cant continue
                    maxProd = 0;
                    maxLen = 0;
                }
            }
            
            // take max after each iteration
            // as values will change in next iteration
            ans = max(ans,maxLen);
        }
        
        // return max
        return ans;
    }
};
