class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        
        uint32_t result = 0;
        
        // result <<= 1 // right shift to make way for new bit
        // result += n&1 // last bit of n
        // n >>= 1 // left shift n to get the penultimate bit
        // by operator precedance n >> i happens first then
        // the last bit is calculated using the bitwise AND
      
        for(int i = 0; i < 32; i++){
            result = (result << 1) + (n>>i&1);
        }
        
        return result;
    }
};
