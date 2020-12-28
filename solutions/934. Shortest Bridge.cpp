class Solution {
public:
    
    struct edge{
        int i;
        int j;
        int c;
    };
        
    void dfs(vector<vector<int> >& arr, int r, int c, queue<edge> &q,  vector<vector<bool> > &vis){
        
        if(r>=arr.size()||r<0 || c>=arr.size()||c<0 || arr[r][c] == 0||arr[r][c]==2)
            return ;
        
        q.push({r, c, 0});
        vis[r][c] = true;
        arr[r][c] = 2;
        dfs(arr, r+1, c, q, vis);
        dfs(arr, r-1, c, q, vis);
        dfs(arr, r, c-1, q, vis);
        dfs(arr, r, c+1, q, vis);
    }
    
    int shortestBridge(vector<vector<int> >& arr) {
        int n = arr.size();
        int r=-1, c=-1;
        vector<vector<bool> >vis(n);
