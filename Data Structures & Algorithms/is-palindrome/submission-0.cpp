class Solution {
public:
    bool check(char c){
        if(c >= 'A' && c <= 'Z' || c >= 'a' && c <= 'z' || c >= '0' && c <= '9' )
            return true;
        else
            return false;
    }
    bool isPalindrome(string s) {
        int n = s.size();
        int j = n-1;
        int i=0;
        while(i<j){
            // cout<<s[i]<<" "<<s[j]<<endl;
            if(check(s[i]) && check(s[j])){
                
                if(tolower(s[i]) != tolower(s[j])) {
                return false;
            }
            else{
                i++;
                j--;
            }
        }
        if(!check(s[i])) i++;
        if(!check(s[j])) j--;

    }

        return true;
    }
};
