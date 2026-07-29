class Solution {
   public:
    string encode(vector<string>& strs) {
        string ans = "";
        for (string& s : strs) {
            ans += (to_string(s.size()))+'#'+s;
        }

        return ans;
    }

    vector<string> decode(string s) {
        // cout<<s<<endl;
        vector<string> ans;
        string t = "";
       int j = 0;
        while(j<s.size()){
            size_t i = s.find('#', j);
            // string len = s.substr(j, i-j+1);
            int len = stoi(s.substr(j, i-j));
            string t = s.substr(i+1, len);
            ans.push_back(t);

            j = i+len+1;

        }
        

        return ans;
    }
};
