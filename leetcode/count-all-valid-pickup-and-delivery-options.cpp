class Solution {
public:
    
    int nchoosek(int n, int k) {
        
        long ans = 1;
        n = n-k+1;
        // nchoosek = n!/(n-k)!(k!)
        // n(n-1)..(n-k+1)/(1*2*3*...k)        
        for(int i = 1; i <= k; i++){
            ans *= n++;
            if(ans%i==0){
                ans/=i;
            }
        }
           
        return ans;
    }
    
    int countOrders(int n) {
        
        if(n==1){
            return 1;
        }
        
        // for first pickup and delivery 
        // pick 2 slots
        // then for the next one pick 2
        // so in total the ways is
        // if there are 2n pairs of pickup and delivery
        // 2nC2 * (2n-2)C2 * ... 2C2
        
        long long ans = 1;
        for(int i = 2*n; i > 2; i-=2){
            ans = ((ans%1000000007)*nchoosek(i,2))%1000000007;
        }
        
        return int(ans);
    }
};
