class NumArray {
public:
    vector<int> pre;
    // vector<int> suf;
    NumArray(vector<int>& nums) {
        int sum = 0;
        
        for(int i=0;i<nums.size();i++){
            sum += nums[i];
            pre.push_back(sum);
        }
        
        // sum = 0;
        // for(int i=nums.size()-1;i>=0;i--){
        //     sum += nums[i];
        //     suf.insert(0, sum);
        // }
    }
    
    int sumRange(int i, int j) {
        if(i==0){
            return pre[j];
        }
        return pre[j] - pre[i-1];
    }
};
​
/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */
