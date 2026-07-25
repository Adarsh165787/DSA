class Solution {
public:
int find(vector<int>& arr) {
        stack<int> st;
        int maxans =0;
        int nse;
        int pse;
        int element;
        for(int i =0;i<arr.size();i++)
        {
            while(!st.empty() && arr[st.top()] >= arr[i]){
             element = st.top();
            st.pop();
            nse = i;
            pse = st.empty() ? -1 : st.top();
            maxans = max(arr[element]*(nse-pse-1),maxans);
        }
        st.push(i);
        }
        while(!st.empty()){
            nse = arr.size();
            element = st.top();
            st.pop();
            pse = st.empty() ? -1 : st.top();
            maxans = max(arr[element]*(nse-pse-1),maxans);
        }
        return maxans;
        }
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty())
            return 0;
        int n= matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> presum(n, vector<int>(m, 0));
        int maxarea = 0;
        for(int j =0;j<m;j++){
            int sum =0;
            for(int i =0;i<n;i++){
               if (matrix[i][j] == '1') {
                sum++;
               }
                else{
                    sum =0;
                }    
                presum[i][j] = sum;
            }
        }
        for(int i =0;i<n;i++){
            maxarea = max(maxarea,find(presum[i]));
        }
        return maxarea;
    }
};