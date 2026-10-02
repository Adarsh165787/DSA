class Solution {
public:
void solve(int open,int close,string current,vector<string> &ans,int n){
    if(open == n && close == n ){
            ans.push_back(current);
            return;
        }
    if(open < n){
    
        solve(open+1,close,current+'(',ans,n);
    }    
    if(close <open){
        solve(open,close+1,current+')',ans,n);
    }
}

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string current;
        solve(0,0,current,ans,n);
        return ans;
    }
};