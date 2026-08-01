class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        unordered_map<char, int> mp;
            int ans = 0;
            int i=0 ; int j= 0;

            int maxFreq = 0;
            char maxChar; 
            while(j< n){    
                mp[s[j]]++;
                maxFreq = max(mp[s[j]], maxFreq);
               
                //window invalid
                while((j-i+1) - maxFreq > k){
                    mp[s[i]]--;
                    i++;
                }

                ans = max(ans, j-i+1);
                j++;
            }
        

        return ans;
    }
};
