class Solution {
public:
    int largestRectangleArea(vector<int>& arr) {
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
};