class Solution {
public:
    //https://leetcode.com/problems/redundant-connection-ii/
​
int find(int x, int *parent){
    if(x == parent[x])
        return x;
    return parent[x] = find(parent[x], parent);
}
​
bool merge(int x, int y, int *parent, int *rank){
    int px = find(x, parent);
    int py = find(y, parent);
    if(px != py){
        if(rank[px] > rank[py])
            parent[py] = px;
        else if(rank[py] > rank[px])
            parent[px] = py;
        else{
            parent[py] = px;
            rank[px]++;
        }
        return true;
    }
    return false;
}
​
vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
    int v = edges.size();
    int *indegree = new int[v];
    int *parent = new int[v];
    int *rank = new int[v];
    for(int i=0;i<v;i++){
        parent[i] = i;
        rank[i] = 1;
        indegree[i] = -1;
    }
    int s, d;
    bool two_parents = false;
    pair<int, int> bl1 = {-1, -1}; //black list edge 1
    pair<int, int> bl2 = {-1, -1}; //black lest edge 2
​
    //case 1 : 2 parents
    //case 2 : just a cycle
    //case 3 : a cycle and 2 parents
​
    //Calculate Indegree
    for(int i=0;i<v;i++){
        s = --edges[i][0];
        d = --edges[i][1];
        if(indegree[d]==-1)
            indegree[d] = s;
        else{
            two_parents = true;
