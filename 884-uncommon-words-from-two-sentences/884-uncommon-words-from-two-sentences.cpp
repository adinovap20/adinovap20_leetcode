class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        string tmp = "";
        s1.push_back(' ');
        s2.push_back(' ');
        unordered_map<string,int> m;
        for(auto x : s1){
            if(x!=' '){
                tmp.push_back(x);
            }else{
                m[tmp]++;
                tmp = "";
            }
        }
        for(auto x : s2){
            if(x!=' '){
                tmp.push_back(x);
            }else{
                m[tmp]++;
                tmp = "";
            }
        }
        vector<string> ans;
        for(auto x : m){
            if(x.second == 1){
                ans.push_back(x.first);
            }
        }
        return ans;
    }
};