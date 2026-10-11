class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        // int n = nums1.size();
        // priority_queue<int> pq;
        // for(int i =0;i<n;i++){
        //     pq.push(abs(nums1[i] - nums2[i]));
        // }
        // int k = k1+k2;
        // while(k >0 && pq.top() > 0){
        //     int maxi = pq.top();
        //     pq.pop();
        //     pq.push(maxi-1);
        //     k--;
        // }
        // long long result =0;
        // while(!pq.empty()){
        //     long long d = pq.top();
        //     pq.pop();
        //     result += (d*d);
        // }
        // return result;
        int n = nums1.size();

        vector<int> diff(n);
        for (int i = 0; i < n; ++i) {
            diff[i] = abs(nums1[i] - nums2[i]);
        }

        int maxDiff = *max_element(diff.begin(), diff.end());

        // countDiff[d] = conut of each diff
        vector<int> countDiff(maxDiff + 1, 0);
        for (int d : diff) {
            countDiff[d]++;
        }

        int K = k1 + k2;

        for (int currDiff = maxDiff; currDiff > 0 && K > 0; currDiff--) {
            int countOps             = min(countDiff[currDiff], K);

            countDiff[currDiff]     -= countOps;
            countDiff[currDiff - 1] += countOps;
            K                       -= countOps;
        }

        
        long long result = 0;
        for (long long d = 1; d <= maxDiff; ++d) {
            result += countDiff[d] * d * d;
        }

        return result;
    }
};