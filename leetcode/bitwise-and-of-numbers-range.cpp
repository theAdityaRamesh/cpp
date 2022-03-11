class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        
        
        
        int ans = 0; // ans variable
        int placeVal = 1; // placeValue
        while(left && right){
            // if left and right have even a single even number
            // then the AND for that place will be zero
            // if both left and right are odd and equal then for
            // that place the AND is 1
            ans += (left&1 && left==right)*placeVal;          
            placeVal = placeVal<<1; // increase placevalue
            left = left>>1; // divide by 2 to check the next place
            right = right>>1;
            // we divide by 2 so we have to check only the units place
        }
        
        return ans;
    }
};
