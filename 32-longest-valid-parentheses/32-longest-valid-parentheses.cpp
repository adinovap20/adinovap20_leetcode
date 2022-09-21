class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.length();
        stack<char> st;
        int ans = 0; int cur = 0;
        vector<bool> visited(n,false);
        stack<pair<char,int>> tmp;
        for(int i=0; i<n; i++){
            char x = s[i];
            if(x=='('){
                tmp.push({'(',i});
            }else{
                if(!tmp.empty()){
                    visited[tmp.top().second] = true;
                    tmp.pop();
                }
            }
        }
        for(int i=0; i<n; i++){
            char x = s[i];
            if(x=='(' && !visited[i]){
                cur = 0;
            }
            if(x=='('){
                st.push('(');
            }else{
                if(st.empty()){
                    cur = 0;
                }else{
                    cur += 2;
                    st.pop();
                }
            }
            ans = max(ans, cur);
        }
        return ans;
    }
};