class Solution {
public:
    string minWindow(string s, string t) {
        vector<int>mps(128,0);
        vector<int>mpt(128,0);
        //keeping a track of characters present in t
        for(char c: t) mpt[c]++;
        int n = s.size();
        int nt = t.size();
        int i=0, j= 0;
        string ans = "";
        int mini = INT_MAX;
        int count = 0;
        while(j<n){
           mps[s[j]]++;

          if (mpt[s[j]] && mps[s[j]] <= mpt[s[j]])
                count++;

            while(count == nt){
                if(mini > j-i+1){
                    mini = j-i+1;
                    ans = s.substr(i, j-i+1);
                }

                mps[s[i]]--;
                if(mpt[s[i]] && mps[s[i]] < mpt[s[i]]) count--;
                i++;
          }
        j++;

        }

    return ans;
        

    }
};
