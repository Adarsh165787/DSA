class Solution {
public:
long long sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> ple(n),nle(n);
        stack<int> st;

        for(int i =0;i<n;i++){
            while(!st.empty() && arr[st.top()] >= arr[i]){
                st.pop();
            }
            ple[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        while(!st.empty()) st.pop();

        for(int i =n-1;i>=0;i--){
            while(!st.empty() && arr[st.top()] > arr[i]){
                st.pop();
            }
            nle[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        long long ans = 0;
        

        for (int i = 0; i < n; i++) {
            long long left = i - ple[i];
            long long right = nle[i] - i;

            ans += 1LL * arr[i] * left * right;
        }
        return ans;
}

long long sumSubarrayMaxi(vector<int>& arr) {
        int n = arr.size();
        vector<int> ple(n),nle(n);
        stack<int> st;

        for(int i =0;i<n;i++){
            while(!st.empty() && arr[st.top()] <= arr[i]){
                st.pop();
            }
            ple[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        while(!st.empty()) st.pop();

        for(int i =n-1;i>=0;i--){
            while(!st.empty() && arr[st.top()] < arr[i]){
                st.pop();
            }
            nle[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        long long ans = 0;
       

        for (int i = 0; i < n; i++) {
            long long left = i - ple[i];
            long long right = nle[i] - i;

            ans += 1LL * arr[i] * left * right;
        }
        return ans;
}

    long long subArrayRanges(vector<int>& nums) {
        return sumSubarrayMaxi(nums)-sumSubarrayMins(nums);
    }
};