class Solution {
public:
    string addBinary(string a, string b) {
        // full adder operation
        // assume that a always has the larger string
        // otherwise swap the 2
        int ptrL = a.size()-1;
        int ptrS = b.size()-1;
        int carry = 0;
        int res;
        
        if(a.size() < b.size()){
            swap(a,b);
            swap(ptrL,ptrS);
        }
        
        
        while(ptrS >= 0){
            res = (a[ptrL]-'0')^(b[ptrS]-'0')^carry;
            carry = (a[ptrL]-'0')&(b[ptrS]-'0') || ((a[ptrL]-'0')^(b[ptrS]-'0'))&carry;
            a[ptrL] = char(res+'0');
            ptrL--;
            ptrS--;
        }

        while(ptrL >= 0 && carry){
            res = (a[ptrL]-'0')^carry;
            carry = (a[ptrL]-'0')&carry;
            a[ptrL--] = char(res+'0');
        }
        
        if(carry){
            a = '1' + a;
        }
        
        return a;
        
    }
};
