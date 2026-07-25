class StockSpanner {
public:
    stack<pair<int,int>> st;
    int indx =-1;

    StockSpanner() {
        
    }
    
    int next(int price) {
        indx++;
        while(!st.empty() && st.top().first <= price){
            st.pop();
        }
        int span;
        if(st.empty()){
            span = indx+1;
        } else{
            span = indx - st.top().second;
        }
        st.push({price,indx});
        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */