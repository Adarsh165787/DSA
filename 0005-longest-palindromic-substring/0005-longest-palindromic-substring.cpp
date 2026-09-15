class Solution {
public:
int expend(string &s,int l,int r){
    while(l >= 0 && r < s.size() && s[l]==s[r]){
        l--;
        r++;
    }
    return r-l-1;
}
    string longestPalindrome(string s) {
        int maxlen = INT_MIN;
        int start =0;
        for(int i =0;i<s.size();i++){
            int len1 = expend(s,i,i);
            int len2 = expend(s,i,i+1);
            int len = max(len1,len2);
            if(len >maxlen){
                maxlen = len;
                start = i-(len-1)/2;
            }
        }
        return s.substr(start,maxlen);
    }
};