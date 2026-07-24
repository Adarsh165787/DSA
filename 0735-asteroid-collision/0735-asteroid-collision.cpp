class Solution {
public:
    vector<int> asteroidCollision(vector<int>& ast) {
        int n = ast.size();
        stack<int> st;
        for(int i =0;i<n;i++){
            bool alive = true;
            while(!st.empty() && st.top() > 0 && ast[i]<0){
                if(abs(ast[i]) > st.top()){
                    st.pop();
                } else if(abs(ast[i]) == st.top()){
                    st.pop();
                    alive = false;
                    break;
                } else{
                    alive = false;
                    break;
                }
            }
            if(alive == true){
                st.push(ast[i]);
            }
        }
        vector<int> ans;
        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};