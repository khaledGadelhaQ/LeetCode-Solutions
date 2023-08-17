class Solution {
public:
  int findKthLargest(vector<int>& nums, int k) {
    priority_queue<int , vector<int>, greater<int> > pq;
    for(auto &val : nums){

      if(pq.size() < k){
        pq.push(val);
      }else if(pq.top() < val){
        pq.push(val); pq.pop();
      }
    }
    return pq.top();
  }
};