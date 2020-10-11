class Solution {
public:
    int countSquares(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        
        int arr[n][m];
//         for(int i=0;i<n;i++){
//             arr[i][0] = mat[i][0];
//         }
        
//         for(int i=0;i<m;i++){
//             arr[0][i] = mat[0][i];
//         }
        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(mat[i][j] == 0){
                    arr[i][j] = 0;
                    continue;
                }
                arr[i][j] = mat[i][j];
                if(i==0 || j==0){
                    ;
                }
                else{
                    arr[i][j] += min(arr[i-1][j-1], min(arr[i][j-1], arr[i-1][j]) ); 
                }
                 
                ans += arr[i][j];
            }
        }
    
        return ans;
    }
    
};
