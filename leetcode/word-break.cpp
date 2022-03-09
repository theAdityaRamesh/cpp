class Solution {
public:
    bool wordBreak(string s, vector<string>& dict) {
     
        // sort the dictionary in lexicographical order
        sort(dict.begin(), dict.end());
        
        // store the positions of the largest words for each alphabet
        vector<int> pos(26,-1);
        int i=0;
        for(string s : dict){
            pos[s[0]-'a'] = i;
            i++;
        }
        
        // 1. In this approach we will start building the string s 
        // from the words in the dictionary. 
        // 2. For each start position we will try and find the maximum 
        // length words that we can fit.
        // 3. store the starting poistion and the index of that word in the 
        // stack
        // 4. Go to the next starting position which is currPos+size of the 
        // choosen word from the dict
        // 5. Now when we find that we dont have a match from the dicitonary
        // or we are going past the string s it means we might have choosen a big word to fit 
        // 6. We unroll the stack and go back one step to the prev starting position and try a
        // smaller word from the dict. If this also fails repeat till we cant find any match and 
        // we are at the starting positon with an empty stack.
        // 
        // OPTIMIZATION TO THIS APPROACH
        // 7. Basically we are doing dfs ont the string and backtracking by unrolling the stack
        // whenever we hit a dead end.
        // 8. So instead of staring afresh each time if we could somehow remmember 
        // till which index we made a valid word in the last calls we can do early stopping
        // 9. IE: if we have already formed a valid word till a certain index and 
        // while unrolling the stack we come to that index where we already have a string
        // made of dict words we can say that we have already tried this path and failed once
        // 10. Hence we need not try again and waste calls
        // 11. So we use a vector lastSol where we store the index of the end of each word at
        // each starting position.
        // 12. And while unrolling if we hit a endIndex of a previous solution and find that we
        // have got a solution uptill that point we stop the search
        
        stack<pair<int,int>> start;
        start.push({0,-1});
        vector<int> lastSol(s.size(),-1);
        
        for(int i = 0; i < s.size(); i++){
            
            int sIndx = start.top().first;
            int dictIndx = start.top().second;
            int prev = -1;  
                       
            if(dictIndx == -1){
                for(int j = pos[s[sIndx]-'a']; j >= 0 && dict[j][0] == s[sIndx]; j--){
                    if(s.compare(sIndx,dict[j].size(), dict[j]) == 0){
                        dictIndx = j;
                        break;
                    }
                }
            } else{                             
                prev = dictIndx;
                for(int j = dictIndx-1; j >= 0 && dict[j][0] == s[sIndx]; j--){
                    if(s.compare(sIndx,dict[j].size(), dict[j]) == 0){
                        dictIndx = j;
                        break;
                    }
                }
                
                if(dictIndx < lastSol[sIndx]){
                    return false;
                }
            }
            if(dictIndx == -1 || dictIndx == prev){
                start.pop();
                if(!start.empty()){
                    i = start.top().first-1;
                } else{
                    return false;
                }
            } else {
                start.top().second = dictIndx;
                i = sIndx+dict[dictIndx].size()-1;
                lastSol[i] = dictIndx;
                start.push({i+1, -1}); 
            }
        }
        
        return true;
    }
};
