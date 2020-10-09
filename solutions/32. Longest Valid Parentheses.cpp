class Solution {
public:
    int longestValidParentheses(string s) {
        int ma=0, m = 0;
        bool flag = false;
        int n = s.size();
        stack<int> stk;
        stk.push(-1);
        // memset(dp, false, sizeof(dp));
        for(int i=0;i<n;i++){
           if(s[i] == '('){
            stk.push(i);   
           }
            else{
                    stk.pop();
                if(stk.empty()){
                    stk.push(i);
                }
                else{
                    ma = max(ma, i - stk.top());
                }
            }
            
        
       
        }
        return ma;
        
    }
};
