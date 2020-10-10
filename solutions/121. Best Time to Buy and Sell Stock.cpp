class Solution {
public:
    int maxProfit(vector<int>& arr) {
        if(arr.size() == 0)
            return 0;
        int me = arr[0];
        int prof = 0;
        for(int i=1;i<arr.size();i++){
            prof = max(prof,  arr[i] - me);
            me = min(me, arr[i]);
        }
        return prof;
    }
};
