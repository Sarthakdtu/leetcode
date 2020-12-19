class Solution {
public:
    bool present(unordered_map<char, int> &freq){
        for(auto w: freq){
            if(w.second>0)
                return false;
        }
        return true;
    }
    
    void update(int &cl, int &ml, int &si, int &l, int &r){
        cl = r- l + 1;
        if(ml>cl){
            si = l;
            ml = cl;
        }
        cout<<si;
    }
    
    string minWindow(string s, string t) {
        unordered_map<char, int> freq;
        int si = -1;
        int cl = 0;
        int ml = s.size()+1;
        for(int i=0;i<t.size();i++)
            freq[t[i]]++;
        
        int l=0, r=0;
        int prevl = 0, prevr=-1;
        while(l<s.size() && r<s.size()){
​
            freq[s[r]]--;            
            if(present(freq)){
                update(cl, ml, si, l, r);
  
                freq[s[l]]++;
                l++;
                bool go = true;
                while(l <= r){
                    if(present(freq)){
                        update(cl, ml, si, l, r);
                    }
                    else
                        break;
                    freq[s[l]]++;
                    l++;
                }
            }
                r++;
        }
        string ans = "";
        if(si != -1){
            for(int i=0;i<ml;i++){
                ans  += s[si+ + i];
            }
        }
        return ans;
    }
};
