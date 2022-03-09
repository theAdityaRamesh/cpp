class Solution {
public:
    int strStr(string haystack, string needle) {
		
		// handle the edge cases
        if(needle.empty()){
            return 0;
        }
		// if we have nothing to search from return -1
        if(haystack.empty() && !needle.empty()){
            return -1;
        }
        
		// if haystack is shorter than needle we can't search
        if(haystack.size() < needle.size()){
            return -1;
        }
        
       // for single length no need to loop        
        if(haystack.size() == 1){
            if(haystack[0] == needle[0]){
                return 0;
            } else{
                return -1;
            }
        }
        
		// scan the entire haystack from left to right
        for(int i = 0; i < haystack.size(); i++){
			// if we find the starting letter
            if(haystack[i] == needle[0]){
				// start scanning from left and right together
                int left = i;
                int right = left+needle.size()-1;
                int next = left;
                if(right > haystack.size()-1){return -1;}
                
                while(left >= 0 && right <= haystack.size()-1 && left <=right){
                    
					// mark the next first occurance to start searching from
					if(next == i && haystack[left] == needle[0]){
						next  = left;
					}
					
					// move the left ptr forward and right pointer backwards
                    if(haystack[left] == needle[left-i] && haystack[right] == needle[right-i]){
                        left++;
                        right--;
                    } else{ // if mismatch break
                        break;
                    }
                }
				// for odd length needles the left will be ahead and right will be behind the centre char
				// for even length needles the left will be 1 step ahead of the right
				// so check for that condition
                if(left - (needle.size()%2+1) == right){
                    return i;
                }
				// search from the next ptr
				if(next != i){
					i = next-1;
				}
				
            }
        }
        
        // if not found return -1
        return -1;
    }
};
