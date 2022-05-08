class Solution {
public:
    string removeOuterParentheses(string s) {
        int ct = 0;
        string ns = "";
        for (char & c : s){
            if (ct - 1 != 0 && c==')'){
                ns+=c;
                ct --;
            }
            else if (ct != 0 && c == '('){
                ns+=c;
                ct ++ ;
            }
            else if (c == '(') ct++;
            else ct--;
        }
        return ns;
    }
};