class Solution {
public:
    int minCost(vector<int>& startPos, vector<int>& homePos, vector<int>& rowCosts, vector<int>& colCosts) {
        int r = startPos[0];
        int c = startPos[1];
        int cost=0;
        while(r !=homePos[0]){
            if(r < homePos[0]){
                r++;
            }else{
                r--;
            }
            cost = cost + rowCosts[r];
        }
        while(c != homePos[1]){
            if(c < homePos[1]){
                c++;
            }else{
                c--;
            }
            cost = cost +colCosts[c];
        }
        return cost;
    }
};