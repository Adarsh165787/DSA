class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& inter) {
        int n = inter.size();
        vector<pair<int,int>> start;
        for(int i =0;i<n;i++){
            start.push_back({inter[i][0],i});
        }
        sort(start.begin(), start.end());
        vector<int> ans(n,-1);
        for(int i=0;i<n;i++){
            int end = inter[i][1];
            int l =0;
            int r = n-1;
            int res =-1;
            while(l <=r){
                int mid = l+(r-l)/2;
                if(start[mid].first >= end){
                    res = start[mid].second;
                    r = mid -1;
                }
                else {
                    l = mid +1;
                }
            }
            ans[i] = res;
        }
        return ans;
    }
};