class Solution {
public:
    int countOdds(int low, int high) {
        low -= low%2;
        high += high%2;
        return (high/2 - low/2);
    }
};
