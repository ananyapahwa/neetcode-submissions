class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        
        for(string& st: strs){
            vector<int> t(26,0);
            for(char c: st){
                t[c-'a']++;
            }
            string s(26, ' ');
            for(int i=0; i<26; i++) s[i] = t[i];
            mp[s].push_back(st);
        }

        vector<vector<string>> ans;
        for(auto& m: mp){
            ans.push_back(m.second);
        }

        return ans;
    }
};
