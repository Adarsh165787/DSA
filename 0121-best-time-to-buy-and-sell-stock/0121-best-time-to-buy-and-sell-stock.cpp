class Solution {
public:
    int maxProfit(vector<int>& num) {
        int n = num.size();
        int buy = num[0];
        int currentprofit =0;
        int maxprofit =0;
        for(int i =1;i<n;i++){
            buy = min(buy,num[i]);
            currentprofit = num[i]-buy;
            maxprofit = max(maxprofit,currentprofit);
        }
        return maxprofit;
    }
};