            indegree[d] = s;
        else{
            two_parents = true;
            bl1 = {indegree[d], d};
            bl2 = {s, d};
        }
    }
​
    pair<int, int> ans;
    bool found = false;
    if(two_parents){    //case 1 or 3
        //check if there is a closed figure 
        for(int i=0;i<v;i++){
            if(edges[i][0] == bl2.first && edges[i][1] == bl2.second)   //ignore edge
                continue;
            if(!merge(edges[i][0], edges[i][1], parent, rank)){
                ans = bl1;  //case 3
                found = true;
                break;
            }
        }
        if(!found)   //case 1
            ans = bl2;
    }
    else{   //case 2
        for(int i=0;i<v;i++){   
            if(!merge(edges[i][0], edges[i][1], parent, rank)){
                ans = {edges[i][0], edges[i][1]};
                break;
            }
        }
    }
    vector<int> final_edge(2);
    final_edge[0] = ans.first+1;
    final_edge[1] = ans.second+1;
    return final_edge;
}
};
