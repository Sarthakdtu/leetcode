class Solution {
public:
    int rec(vector<int> arr, int idx, int dp[]){
        if(idx >= arr.size()){
            return 0;
        }
        if(dp[idx]!=-1)
            return dp[idx];
        dp[idx] = max(rec(arr, idx+1, dp), rec(arr, idx+2, dp) + arr[idx]);
        return dp[idx];
    }
    
    int rob(vector<int>& nums) {
        int dp[nums.size()];
        memset(dp, -1, sizeof(dp));
        return rec(nums, 0, dp);
    }
};
