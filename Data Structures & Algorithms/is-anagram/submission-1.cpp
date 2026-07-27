class Solution {
public:
    bool isAnagram(string s, string t) {
        int n = s.size();
        int m = t.size();

        if(n != m) return false;

        unordered_map<char,int> mp;

        for(char c: s) mp[c]++;

        for(char c: t) mp[c]--;

        for (char c: s) {
            if(mp[c] != 0) return false;
        }


        return true;
    }
};
