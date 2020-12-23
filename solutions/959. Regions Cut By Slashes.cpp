class Solution {
public:
    int find(int x, int parent[]){
        if(x == parent[x])
            return x;
        return parent[x] = find(parent[x], parent);
    }
    
    void merge(int x, int y, int parent[], int rank[], int &regions){
        int px = find(x, parent);
        int py = find(y, parent);
        // cout<<"Merging "<<x<<" and "<<y<<endl;
        if(px != py){
            // cout<<"Merged "<<endl;
            if(rank[px] > rank[py])
                parent[py] = px;
            else if(rank[py] > rank[px])
                parent[px] = py;
            else{
                parent[px] = py;
                rank[py]++;
            }
        }
        else{
            // cout<<"Increasing regions "<<x<<" and "<<y<<endl;
            regions++;
        }
    }
    
    int regionsBySlashes(vector<string>& arr) {
        //. . . . . .
        //.
        //.
        //.Connect borders
        //. . . . . .
        //cell_number = row*totola_num_cols + col
        //number of points = n+1
        
        int n = arr.size();
        int num_points = (n+1)*(n+1);
        
        int parent[num_points];
        int rank[num_points];
        int regions = 0;
        
        memset(rank, 1, sizeof(rank));
        
        for(int i=0;i<num_points;i++)
