class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        int i =0,j=0,sum=0;
        int len =INT_MAX;
        int bestmin = INT_MAX;
        int result = INT_MAX;
        vector<int> bestmintillind(n,INT_MAX);
        while(j<n){
            sum += arr[j];
            while( sum > target){
                sum -= arr[i];
                i++;
            }
            if(sum == target){
                len = j-i+1;
                if(i >0 && bestmintillind[i-1] != INT_MAX){
                    result = min(result,bestmintillind[i-1]+len);
                }
                bestmin = min(bestmin,len);
            }
            bestmintillind[j] = bestmin;
            j++;
        }
        return result == INT_MAX ? -1 : result;
    }
};