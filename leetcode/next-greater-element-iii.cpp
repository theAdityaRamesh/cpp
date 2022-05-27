class Solution {
public:
    int nextGreaterElement(int n) {
        
        // same concept as next_permutation
        // if the digits are all increasing we can't
        // find a larger number as if we swap any
        // then a smaller digit will end up in a larger
        // place value and thus the value decreases
        // eg : 654321
        
        // hence the aim is to find the first number which decreases
        // after the increasing sequence starting at the ones place.
        // we will call this number next
        // now to find the next largest number we have to increase the 
        // number by the smallest possible increment
        // which is equivalent to changing the place value
        // of the next place with the smallest possible number
        // from the sorted seq behind next.
        
        // to do this we pick the number just greater than next
        // swap it with it. 
        // now we will reverse the seq after next to ensure that 
        // the largest numbers have the smallest place value/
        
        string dig = to_string(n);
        int next = dig.size()-2;
        while(next >= 0 && dig[next] >= dig[next+1]){
            next--;
        }
        
        if(next == -1){
            return -1;
        }
        
        int prev = dig.size()-1;
        while(prev > next && dig[prev] <= dig[next]){
            prev--;
        }
        swap(dig[next], dig[prev]);
        reverse(dig.begin()+next+1, dig.end());
        
        try{ // to catch numbers which are larger than int_max
            return stoi(dig);
        } catch(out_of_range){
            return -1;
        }
        
    }
};
