class StockSpanner {
public:
    StockSpanner() {
        
    }
    

    stack<pair<int,int>> st;  // {price, span}

  
    
    int next(int price) {
        int span = 1;
        
        // pop all smaller or equal
        while(st.size() > 0 && st.top().first <= price){
            span += st.top().second;
            st.pop();
        }
        
        st.push({price, span});
        return span;
    }
};
    


/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */