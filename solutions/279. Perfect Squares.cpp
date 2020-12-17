class Solution {
public:
    int numSquares(int n) {
        if(n==1)
            return 1;
        int dp[n+1];
        vector<int> sqr;
        for(int i=1;i<=n/2;i++){
            sqr.push_back(i*i);
        }
        // memset(dp, n+1, sizeof(dp));
        dp[0] = 0;
        for(int i=1;i<=n;i++){
            dp[i] = i;
            for(int j=0;j<sqr.size();j++){
                if(i >= sqr[j]){
                    // cout<<dp[i]<<" ";
                    dp[i] = min(dp[i], dp[i-sqr[j]]+1);
                    // cout<<dp[i]<<" ";
                    // cout<<"Using "<<sqr[j]<<" for "<<i<<endl;
                }
                else{
                    // cout<<dp[i]<<endl;
                    break;
                }
            }
        }
     
        return dp[n];
        
    }
};
