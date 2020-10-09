class Solution {
public:
    int maxProfit(vector<int>& arr) {
        int n = arr.size();
        if(n<=1)
            return 0;
        // if(n==2){
        //     return max(arr[0]-arr[1], 0);
        // }
        int p[n];
        memset(p, 0, sizeof(p));
        int me = arr[n-1];
        for(int i=n-2;i>=0;i--){
            me = max(me, arr[i]);
            p[i] = max(p[i+1], me - arr[i]);
        }
        me = arr[0];
        for(int i=1;i<n;i++){
            me = min(me, arr[i]);
            p[i] = max(p[i-1],p[i] + arr[i] - me);
        }
        return p[n-1];
    }
};
