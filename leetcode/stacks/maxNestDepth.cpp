class Solution {
public:
    int maxDepth(string s) {
        int ct = 0;
        int d=0;
        for (char &c : s){
            if (c=='('){
                ct++;
                d = max(d, ct);
            }
            else if(c == ')' && c>0) ct--;
        }
        return d;
    }
};