class Solution {
public:
    int evaluate(int num1, int num2, string opr){
        if(opr == "+") return num1+num2;
        else if(opr == "-") return num2-num1;
        else if(opr == "*") return num1 * num2;
        else return num2/num1;
    }
    int evalRPN(vector<string>& tokens) {
        stack<int>st;

        for(string s: tokens){
            if(s != "+" && s!= "*" && s!= "-" && s!= "/"){
                st.push(stoi(s));
            }else{
                int num1 = st.top();
                st.pop();
                int num2 = st.top();
                st.pop();
                int ans = evaluate(num1, num2, s);
                st.push(ans);
            }
        }

        return st.top();
    }
};
