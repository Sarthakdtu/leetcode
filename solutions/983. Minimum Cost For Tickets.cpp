class Solution {
public:
    int mincostTickets(vector<int>& arr, vector<int>& cost) {
        vector<int> dp(366);
        int n = arr.size();
        dp[arr[n-1]] = min(cost[0], min(cost[1], cost[2]));
        for(int i=n-2;i>-1;i--){
            dp[arr[i]] = cost[0] + dp[arr[i+1]];
            int j;
            for(j=i+1;j<n;j++)
                if(arr[i] + 6 < arr[j])
                    break;
            if(j==n)
                dp[arr[i]] = min(dp[arr[i]], cost[1]);
            else
                dp[arr[i]] = min(dp[arr[i]], dp[arr[j]] + cost[1]);
            
            for(j=i+1;j<n;j++)
                if(arr[i] + 29 < arr[j])
                    break;
            if(j==n)
                dp[arr[i]] = min(dp[arr[i]], cost[2]);
            else
                dp[arr[i]] = min(dp[arr[i]], dp[arr[j]] + cost[2]);
        }
        return dp[arr[0]];
    }
};
