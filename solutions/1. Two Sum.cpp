class Solution {
public:
    vector<int> twoSum(vector<int>& arr, int k) {
        // int f=0, s=arr.size()-1;
        vector<int> ans;
        map<int, int> freq;
        for(int i=0;i<arr.size();i++){
            freq[arr[i]] = i+1;
        }
        for(int i=0;i<arr.size();i++){
            int index = freq[k - arr[i]];
            if(index>0 && index !=i+1){
                ans.push_back(i);
                ans.push_back(index-1);
                break;
            }
        }
        return ans;
        
    }
};
