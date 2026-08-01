class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int>mp;
        int n = s.size();

        for(char c: s) mp[c]++;
        int ans = 0;
        for(auto& m: mp){
            char c = m.first;
            int i=0; int j= 0;
            int ct = 0;
            while(j< n){
                if(s[j] != c){
                    ct++;
                }

                //window invalid
                if(ct > k){
                    if(s[i] != c) ct--;
                    i++;
                }

                ans = max(ans, j-i+1);
                j++;
            }
        }

        return ans;
    }
};
