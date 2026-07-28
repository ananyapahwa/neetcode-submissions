class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<vector<int>, vector<string>> mp;
        
        for(string& s: strs){
            vector<int> t(26,0);
            for(char c: s){
                t[c-'a']++;
            }

            mp[t].push_back(s);
        }

        vector<vector<string>> ans;
        for(auto& m: mp){
            ans.push_back(m.second);
        }

        return ans;
    }
};
