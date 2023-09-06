class Solution {
public:
    int calPoints(vector<string>& op) {
        stack<int> st;
        for(int i = 0 ; i < (int) op.size() ; i++ ){
            if(op[i] == "+"){

              int tmp = st.top(); st.pop();
              int tmp2 = tmp+ st.top();
              st.push(tmp); st.push(tmp2);

            }else if(op[i] == "C")
              st.pop();
            else if(op[i] == "D")
              st.push(st.top()*2);
            else
              st.push(stoi(op[i]));    
        }
        int res {0};
        while(!st.empty()){
			res += st.top(); st.pop();
		}
        return res;
    } 
};