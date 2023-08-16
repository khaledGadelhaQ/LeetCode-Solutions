class MinStack {
public:
    stack<pair<int,int>> st;
    int mn {0};
    MinStack() {}
    
    void push(int val) {
      if(st.empty()){
        st.push({val,val});
        mn = val;
      }else{
        mn = min(val,st.top().second);
        st.push({val,mn});
      }
    }
    
    void pop() {
   
     if(!st.empty())
        st.pop();

    } 
    
    int top() {
     if(!st.empty())
        return st.top().first ;
      return 0 ;
    }
    
    int getMin() {
      if(!st.empty())
        return st.top().second ;
      return 0 ;
    }

};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */