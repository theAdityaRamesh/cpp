class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graphs) {

        stack<vector<int>> paths; // maintain a stack of paths
        vector<vector<int>> ans; // ans variable
        paths.push({0}); // push zero because we are starting from 0 always
        int last = graphs.size()-1; // n-1 is the last node
            
        while(!paths.empty()){
            // get the current traversed path
            vector<int> top = paths.top();
            // remove it from the stack
            paths.pop();
            // curr node is the one we pushed int the last call
            int curr = top.back();
            
            // if we have reached the last node
            // push the path into ans
            if(curr == last){
                ans.push_back(top);
            } else{
                // otherwise 
                // go to all the possible nodes
                // that are connected to the current node
                for(int i : graphs[curr]){
                    top.push_back(i);
                    paths.push(top);
                    top.pop_back();
                }  
            }
        }
            
        // graphs.erase(graphs.begin(), graphs.begin()+last+1);
        return ans;
    }
};
