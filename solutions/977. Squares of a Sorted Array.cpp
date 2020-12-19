class Solution {
public:
    vector<int> sortedSquares(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans(n);
        
        int l=0, r=n-1;
        int i = n-1;
        while(l<=r){
            int l2 = arr[l] * arr[l];
            int r2 = arr[r] * arr[r];
            if(l2 > r2){
                ans[i] = l2;
                l++;
            }
            else{
                ans[i] = r2;
                r--;
            }
            i--;
        }
        return ans;
    }
};
