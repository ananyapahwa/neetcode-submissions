// Time Complexity: O(m * n)
//   - m = number of strings
//   - n = length of the longest string
// Space Complexity: O(m*n)
//
// Note:
//   This implementation stores frequency counts as characters
//   (s[i] = freq[i]). It is correct under LeetCode's constraints
//   because each string length <= 100, so every count fits in a char.
//   However, for larger strings this can overflow, causing different
//   frequency arrays to produce the same key. A production-quality
//   solution should encode the integer counts (e.g., "#1#0#2...") or
//   use array<int, 26> with a custom hash.

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
