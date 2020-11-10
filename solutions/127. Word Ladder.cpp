class Solution {
public:
    struct res{
        string w;
        int dis;
    };
    
    int ladderLength(string b, string e, vector<string>& words) {
        // if(b==e)
        //     return 0;
        queue<res> q;
        q.push({b, 1});
        map<string, int> m;
        unordered_set<char> alp;
        for(int i=0;i<words.size();i++){
            m[words[i]] = 1;
            for(int j=0;j<words[i].size();j++){
                alp.insert(words[i][j]);
            }
        }
        
        map<string, int> vis;
        while(!q.empty()){
            res a = q.front();
            q.pop();
            if(a.w == e){
                return a.dis;
            }
            for(int i=0;i<a.w.size();i++){
                string curr = a.w;
                for(auto itr=alp.begin();itr!=alp.end();itr++){
                    char ch = *itr;
                    curr[i] = ch;
                    if(m[curr]==1 && vis[curr]==0){
                        q.push({curr , a.dis+1});
                        vis[curr] = 1;
                    }
                }
            }
        }
        return 0;
    }
};
