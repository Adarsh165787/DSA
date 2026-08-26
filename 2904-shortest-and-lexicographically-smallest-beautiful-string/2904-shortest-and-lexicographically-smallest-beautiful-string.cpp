class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n =s.size();
        int l =0;
        int one=0;
        string ans ="";
        for(int i =0;i<n;i++){
            if(s[i]=='1'){
                one++;
            }
            while(one >k){
                if(s[l]=='1'){
                    one--;
                }
                l++;
            }
            if(one ==k){
                while(s[l]=='0'){
                    l++;
                }
                string curr = s.substr(l,i-l+1);
                if (ans == "" ||
                    curr.size() < ans.size() ||
                    (curr.size() == ans.size() && curr < ans)) {
                    ans = curr;
                }
            }
        }
        return ans;
    }
};