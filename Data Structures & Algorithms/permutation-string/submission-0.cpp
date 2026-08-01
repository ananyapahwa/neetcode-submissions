class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int f1[26] = {0};
        int f2[26] = {0};

        //counting the charcaters in s1
        for(char c: s1) f1[c-'a']++;

        int k = s1.size();  //window size
        int n = s2.size();
        int i=0, j=0;
        while(j<n){
            f2[s2[j]-'a']++;

            if(i<n && j-i+1 == k){
                if(equal(f1, f1 + 26, f2)) return true;

                f2[s2[i]-'a']--;
                i++;
            } 

            j++;
        }

        return false;
    }
};
