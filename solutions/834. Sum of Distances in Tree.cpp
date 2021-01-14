    }
​
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<int> num_nodes(n, 1);
        vector<int> v;
        vector<vector<int> > tree(n, v);
        vector<int> distance(n, 0);
        vector<bool> vis(n, false);
​
        for(int i=0;i<edges.size();i++){
            tree[edges[i][0]].push_back(edges[i][1]);
            tree[edges[i][1]].push_back(edges[i][0]);
        }
​
        count_nodes(0, tree, num_nodes, vis);
        
        int sum = relative_bfs(n, 0, tree);
        vis = vector<bool>(n, false);
        distance[0] = sum;
        // cout<<sum;
        calc_distance(n, 0, tree, distance, num_nodes, vis);
        
        return distance;
    }
};
