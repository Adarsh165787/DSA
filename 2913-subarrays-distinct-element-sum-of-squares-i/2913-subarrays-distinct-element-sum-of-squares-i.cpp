class Solution {
public:
    int sumCounts(vector<int>& arr) {
        int n = arr.size();
        int ans=0;
        for(int i =0;i<n;i++){
            set<int> s;
            for(int j =i;j<n;j++){
                s.insert(arr[j]);
                ans += s.size()*s.size();
            }
        }
        return ans;
    }
};