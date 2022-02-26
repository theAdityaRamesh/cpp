// 2 stacks front and back
// // while doing push/pop
// check which stack is empty
// and use the the other stack
// maintain top and qSize vars
// for peek and empty funcs

class MyQueue {
public:    
    MyQueue() {
        qSize = 0;
    }
    
    void push(int x) {
        if(qSize == 0){
            top = x;
        } qSize++;
        
        if(!front.empty()){
            while(!front.empty()){
                back.push(front.top());
                front.pop();
            } back.push(x);
        } else {
            back.push(x);
        }
    }
    
    int pop() {
        
        int ans = top;
        qSize--;
        if(!front.empty()){
            // if front stack is not empty
            // ie back stack is empty
            front.pop();
            if(!front.empty()){
                top = front.top();
            }
            while(!front.empty()){
                back.push(front.top());
                front.pop();
            }
        } else {
            // if front stack is empty
            // ie back stack is not empty
            while(!back.empty()){
                front.push(back.top());
                back.pop();
            } 
            
            front.pop();
            if(!front.empty()){
                top = front.top();
            }
        }
        return ans;
    }
    
    int peek() {
        return top;
    }
    
    bool empty() {
        return !bool(qSize);
    }
    
private:
    int qSize;    
    int top ;
    stack<int> back ;
    stack<int> front ;
    
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
