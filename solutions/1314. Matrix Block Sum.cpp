            for(int j= 0;j<m;j++){
                if(i==0 && j==0 ){
                    arr[i][j] = mat[i][j];
                }
                else if(i==0){
                    arr[i][j] = mat[i][j] + arr[i][j-1];
                }
                else if(j==0){
                    arr[i][j] = mat[i][j] + arr[i-1][j];
                }
                else
                    arr[i][j] = arr[i][j-1] + arr[i-1][j] - arr[i-1][j-1] +mat[i][j];
            }
        }
        
        vector<vector<int> > ans(n, vector<int>(m));
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<m;j++){
        //         cout<<arr[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int imk = max(0, i - k);
                int ipk = min(n-1, i + k);
                int jmk = max(0, j - k);
                int jpk = min(m-1, j + k);
                // cout<<"At "<<i<<" "<<j<<endl;
                // cout<<"From "<<imk<<" to "<<ipk<<endl;
                // cout<<"From "<<jmk<<" to "<<jpk<<endl;
                ans[i][j] = arr[ipk][jpk];
                if(imk-1>=0)
                    ans[i][j] -= arr[imk-1][jpk];
                if(jmk-1>=0)
                    ans[i][j] -= arr[ipk][jmk-1];
                if(imk >=1 && jmk>=1)
                    ans[i][j] += arr[imk-1][jmk-1];
            }
        }
        
        return ans;
        
        
        
        
    }
};
