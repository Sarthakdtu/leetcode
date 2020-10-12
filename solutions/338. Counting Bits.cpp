class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans;
        ans.push_back(0);
        if(n==0){
            return ans;
        }
        ans.push_back(1);
        if(n == 1){
            return ans;
        }
        int dp[n+1];
        memset(dp, 0, sizeof(dp));
        
        dp[0] = 0;
        dp[1] = 1;
        int p = 2;
        map<int, int> po;
        for(int i=2;i<=n;i*=2){
            po[i] = 1;
        }
        for(int i=2;i<=n;i++){
            if(po[i]==1){
                p = i;
                dp[i] = 1;
            }
            else{
                dp[i] = dp[p] + dp[i - p];
            }
            ans.push_back(dp[i]);
            
        }
        return ans;
        
        
    }
};
