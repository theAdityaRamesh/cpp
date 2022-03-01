class Solution {
public:
    vector<int> countBits(int n) {
        
        vector<int> bits(n+1,0);        
        // 0 : 000
//         1 : 001
//         2 : 010 = 1 << 1 (1x2) = bits in (2/2) = 1
//         3 : 011 = (2 + 1) so last bit becomes 1 hence bits[2] + 1
//         4 : 100 = (2 << 1) so = bits in 2
//         5 : 101 = (4+1) so bits in 4 + 1
//         ... and so on
        
        for(int i = 1; i < n+1; i++){
            if(i&1){
                bits[i] = bits[i-1]+1;
            } else {
                bits[i] = bits[i/2];
            }
        }
        
        return bits;
    }
};
