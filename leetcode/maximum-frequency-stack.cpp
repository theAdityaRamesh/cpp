class FreqStack {
public:
    FreqStack() {
        
    }
    
    // create freq bins for each freq
    // create a mapping b/w each unique value to its freq
    // since we have to return the most recent elemetn for each freq
    // we make a stack and return the latest pushed element
    // if we empty the freq bin we move to the prev freq bin
    // for each new element increase freq by 1 and push it into the freq bin stack
    void push(int val) {
        if(freq.find(val) == freq.end()){
            freq.insert({val,1});
            buckets[1].push(val);
        } else{
            maxFreq = max(maxFreq, ++freq[val]);
            buckets[freq[val]].push(val);
        }
    }
    
    int pop() {
      
        int ans = buckets[maxFreq].top();
        buckets[maxFreq].pop();
        if(buckets[maxFreq].empty()){
            buckets.erase(maxFreq);
            maxFreq--;
        }
        
        freq[ans]--;
        
        return ans;
    }
    
private:
    
    unordered_map<int,stack<int>> buckets;
    unordered_map<int,int> freq;
    int maxFreq = 1;

};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */
