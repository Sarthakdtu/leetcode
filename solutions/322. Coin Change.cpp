class Solution {
public:
   int coinChange(vector<int>& coins, int amount) {
    int dp[amount+1];
    memset(dp, 10001, sizeof(dp));
​
    dp[0] = 0;
    for(int i=1;i<=amount;i++){
        for(int j=0;j<coins.size();j++){
            if(coins[j] <= i){
                // cout<<i<<" "<<coins[j]<<endl;
                dp[i] = min(dp[i], dp[i - coins[j]] + 1);
            }
        }
    }
       // cout<<dp[amount]<<endl;
    if(dp[amount] >= 10001)
        return -1;
    return dp[amount];
}
};
