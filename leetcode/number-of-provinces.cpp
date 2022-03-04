class Solution {
public:
    
    void visitAllProvinces(vector<vector<int>>& isConnected, int i, int size){
        
        int city = i;
        for(int i = 0; i < size; i++){
            if(isConnected[city][i] == 1){
                // scan thru the connections of the city
                isConnected[i][i] = 2;
                // mark the conncected city as visited
                isConnected[i][city] = 2;
                // mark the connection both ways as visited
                isConnected[city][i] = 2;
                // before continuing
                // visit the other cities connected with the current connection
                // found
                visitAllProvinces(isConnected, i, size);
            }
        }
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        
        // basically is connected is an adjacency matrix
        // get num of cities
        int city = isConnected.size();
        // intially number of provinces is zero
        int ans = 0;
        // iterate thru the number of cities
        for( int i = 0; i < city; i++){
            // i,i node is the connection of the city with itself
            // which we can use to keep track of the visited status of the city
            if(isConnected[i][i] != 2){
                // if we find a unvisited city
                // increase number of provinces by 1
                ans++;
                // go and visit all the cities connected recursively
                visitAllProvinces(isConnected, i, city);
            }
        }
        
        return ans;
    }
};
