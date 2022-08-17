class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> conv = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        set<string> st;
        for(auto x : words){
            string tmp;
            for(auto y : x){
                tmp = tmp + conv[y-'a'];
            }
            st.insert(tmp);
        }
        return st.size();
    }
};