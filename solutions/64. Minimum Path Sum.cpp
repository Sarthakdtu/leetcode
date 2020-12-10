class Solution {
public:
    int minPathSum(vector<vector<int>>& cost) {
        int n = cost.size();
        int m = cost[0].size();
        vector<vector<int> > dp(n);
        
        for(int i=0;i<n;i++){
            dp[i] = vector<int>(m, 1000);
            for(int j=0;j<m;j++){
                if(i==0 && j==0 ){
                    dp[i][j] = cost[i][j];
                    continue;
                }
                if(i == 0){
                    dp[i][j] = dp[i][j-1] + cost[i][j];
                    continue;
                }
                if(j == 0){
                    dp[i][j] = dp[i-1][j] + cost[i][j];
                    continue;
                }
            
                dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + cost[i][j];
            }
        }
        return dp[n-1][m-1];
    }
};
