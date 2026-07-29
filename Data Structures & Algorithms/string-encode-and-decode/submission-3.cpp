class Solution {
   public:
    string encode(vector<string>& strs) {
        string ans = "";
        for (string& s : strs) {
            ans += s + '#'+(to_string(s.size()))+'#';
        }

        return ans;
    }

    vector<string> decode(string s) {
        // cout<<s<<endl;
        vector<string> ans;
        string t = "";
        for(int i=0; i<s.size(); i++){
            if(s[i] == '#' ){
                int temp = i+1;
                string sz = "";
                while(temp < s.size() && s[temp]!= '#' && s[temp] >= '0' && s[temp] <= '9'){
                    sz += s[temp];
                    temp++;
                }
                // // cout<<sz<<endl;
                // cout<<t<<endl;
                if(!sz.empty() && stoi(sz) == t.size() && s[temp] == '#'){
                    // cout<<sz<<endl<<"hell";
                    i=temp;
                    ans.push_back(t);
                    t="";
                }else{
                    t += s[i];
                }
            }else{
                t += s[i];
            }
        }

        return ans;
    }
};
