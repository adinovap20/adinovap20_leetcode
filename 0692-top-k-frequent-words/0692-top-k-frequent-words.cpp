class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int> m;
        for(auto x : words){
            m[x]++;
        }
        vector<pair<int,string>> arr;
        for(auto x : m){
            arr.push_back({x.second, x.first});
        }
        function<bool(pair<int,string>, pair<int,string>)> cmp = [&](pair<int,string> a, pair<int, string> b){
            if(a.first == b.first){
                return a.second < b.second;
            }
            return a.first > b.first;
        };
        sort(arr.begin(),arr.end(),cmp);
        vector<string> ret;
        for(int i=0; i<k; i++){
            ret.push_back(arr[i].second);
        }
        return ret;
    }
};