class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;
        int n = num.size();
        for(int i =0;i<n;i++){
            while(!st.empty() && k>0 && st.top()-'0' > num[i]-'0'){
                st.pop();
                k = k-1;
            }
            st.push(num[i]);
        }
        while(k>0) {
            st.pop();
            k--;
            }
        if(st.empty()) return "0";
        string ans ="";
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        int i = 0;
        while (i < ans.size() && ans[i] == '0')
            i++;

        ans = ans.substr(i);

        return ans.empty() ? "0" : ans;

    }
};