class Solution {
public:
    int countCommas(int n) {
        int ans;
        if(n <1000){
            return 0;
        }
        if(n >1000){
            ans = n-1000+1;
        }
        return ans;
    }
};