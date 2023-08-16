class KthLargest {
public:
    priority_queue<int , vector<int> , greater<int>> pq ;
    int kk {0} ;
    KthLargest(int k, vector<int>& nums) {
      kk = k ;
      for(auto val  : nums)
       add(val);
     

    }
    
    int add(int val) {
      
        if(pq.size() < kk)
          pq.push(val);

        else if(pq.top() < val){
          pq.pop();
          pq.push(val);
        }
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */