class Solution {
public:
    string minWindow(string s, string t) {
        //explanation https://www.youtube.com/watch?v=e1HlptlipB0&t=1302s
        int i = 0, j = -1;
        int start_index = -1, min_len = s.size()+1;
        unordered_map<char, int> tfreq;
        unordered_map<char, int> sfreq;
        int match_count = t.size();
        
        for(int i=0;i<t.size();i++){
            tfreq[t[i]]++;    
        }
        int curr_count=0;
        while(true){
            //acquire
            while(i<s.size() && match_count!=curr_count){
                if(tfreq[s[i]] !=0 && sfreq[s[i]] < tfreq[s[i]])
                    curr_count++;
                sfreq[s[i]]++;
                i++;
            }
            if(match_count == curr_count){
                int curr_len = (i - 1) - (j + 1) + 1;
                if(curr_len < min_len){
                    start_index = j+1;
                    min_len = curr_len;
                }
            }
            //release
            while(j!=i){
                j++;
                sfreq[s[j]]--;
                if(tfreq[s[j]]!=0 && sfreq[s[j]] < tfreq[s[j]])
                    curr_count--;
                if(match_count == curr_count){
                    int curr_len = (i - 1) - (j + 1) + 1;
                    if(curr_len < min_len){
                        start_index = j+1;
                        min_len = curr_len;
                    }
                }
                else
                    break;
            }
           
            if(i == s.size())
                break;
        }
        
        if(start_index!=-1){
            string ans = "";
            for(i=start_index;i<(start_index+min_len);i++){
                ans += s[i];
            }
            return ans;
        }
        return "";
    }
};
