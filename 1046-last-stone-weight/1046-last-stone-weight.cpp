class Solution {
public:
  int lastStoneWeight(vector<int>& stones) {
    priority_queue<int> pq ;
    for(int i = 0 ; i < stones.size()  ; i++){
      pq.push(stones[i]);
    }

    while(pq.size() > 1){
      int first = pq.top() ; pq.pop() ;
      int sec = pq.top() ; pq.pop() ;

      if(first != sec){
        pq.push(abs(first-sec));
      }
    }
    if(pq.empty())
      return 0;
    return pq.top();
  }
};