class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        
        int rSize = accounts.size();
        int cSize = accounts[0].size();
        int paisa = 0;
        
        // go thru each customers account
        for(int row = 0; row < rSize; row++){
            int curr = 0;
            // sum their money
            for(int col = 0; col < cSize; col++){
                curr += accounts[row][col];
            }
            // take max and replace if larger
            paisa = max(paisa, curr);
        }
        
        return paisa;
    }
};
