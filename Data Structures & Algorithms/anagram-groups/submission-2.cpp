class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        
        for(string& st: strs){
            vector<int> t(26,0);
            for(char c: st){
                t[c-'a']++;
            }
            string key;
            for(int i=0; i<26; i++){
                key+= "#";
                key += to_string(t[i]);
            }
            mp[key].push_back(st);
        }

        vector<vector<string>> ans;
        for(auto& m: mp){
            ans.push_back(move(m.second));
        }

        return ans;
    }
};
