// Frequency Count + Hash Map
//
// Intuition:
//   Two strings are anagrams if and only if they have identical
//   character frequency counts. Instead of sorting each string,
//   compute its frequency signature and use it as the hash map key.
//
// State:
//   mp[key] = list of all strings sharing the same frequency signature.
//
// Key:
//   Encode the 26-character frequency array into a unique string
//   (e.g., "#1#0#2#...") to avoid collisions.
//
// Why is this optimal?
//   - Counting character frequencies takes O(n) for each string.
//   - Building the key takes O(26) = O(1) since the alphabet size is fixed.
//   - unordered_map provides O(1) average insertion and lookup.
//   - Unlike the sorting approach (O(n log n) per string),
//     this avoids sorting altogether, giving a linear-time solution.
//
// Time Complexity:
//   O(m * n)
//     - m = number of strings
//     - n = length of the longest string
//
// Space Complexity:
//   O(m) (excluding the output)
//   The hash map stores one key for each unique anagram group.
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
