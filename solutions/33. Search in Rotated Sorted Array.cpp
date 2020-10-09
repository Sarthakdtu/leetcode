class Solution {
public:
    int pivot(vector<int> arr, int start, int end){
        
        if(start>end)
            return -1;
        if(start==end)
            return start;
        
        int mid  = (start+end)/2;
        if(mid-1 >=start && arr[mid-1]>arr[mid]){
            return mid;
        }
        if(mid+1<end && arr[mid]>arr[mid+1])
            return mid+1;
        if(arr[start] <= arr[mid])
            return pivot(arr, mid+1, end);
        return pivot(arr, start, mid);
        
    }
    
    int bin(vector<int> &arr, int key, int start, int end ){
        if(start>=end)
            return -1;
        int mid = (start+end)/2;
        if(arr[mid] == key)
            return mid;
        if(arr[mid]>key)
            return bin(arr, key, start, mid);
        if(arr[mid]<key)
            return bin(arr, key, mid+1, end);
        return -1;
    }
    
    
    int search(vector<int>& nums, int target) {
        int p = pivot(nums, 0, nums.size());
        // cout<<p<<endl;
        if(p==INT_MAX){
            p = 0;
        }
        int ans = bin(nums, target, p, nums.size());
        if(ans!=-1){
            return ans;
        }
        return bin(nums, target, 0, p);
            
    }
};
