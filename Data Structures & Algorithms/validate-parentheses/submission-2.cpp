class Solution {
public:
    bool isCorrect(char o, char c){
        if(o=='[' && c==']' || o=='(' && c==')' || o=='{' && c=='}')
            return true;
        else return false;
    }
    bool isValid(string s) {
        if(s.size() % 2 != 0) return false;
        stack<char>st;
        for(int c: s){
            //open bracket
            if(c=='(' || c== '{' || c== '[') st.push(c);

            else{
                if(st.empty()) return false;
                if(isCorrect(st.top(), c)) st.pop();
                else return false;
            }
        }

        return st.empty();
    }
};
