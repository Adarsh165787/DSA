class Solution {
public:
    string removeOuterParentheses(string s) {
        int n = s.size();
        int count =0;
        int start =0;
        for(int i =0;i<n;i++){
            if(s[i] == '('){
                count++;
                if (count == 1) {
                    start = i;
                }
            }else {
                count--;
                if(count ==0){
                    s[start] ='#';
                    s[i] ='#';
                }
            }
        }
        s.erase(remove(s.begin(), s.end(), '#'), s.end());
        return s;
    }
};