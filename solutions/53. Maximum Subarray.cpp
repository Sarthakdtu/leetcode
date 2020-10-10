class Solution {
public:
    int maxSubArray(vector<int>& arr) {
        int curr=0, m = arr[0];
        int n = arr.size();
        for(int i=0;i<n;i++){
            if(arr[i]>=0){
                m = arr[i];
                break;
            }
            m = max(arr[i], m);
        }
        if(m<0)
            return m;
        for(int i=0;i<n;i++){
            curr += arr[i];
            m = max(curr, m);
            if(curr<0)
                curr  =0;
        }
        return m;
    }
};
