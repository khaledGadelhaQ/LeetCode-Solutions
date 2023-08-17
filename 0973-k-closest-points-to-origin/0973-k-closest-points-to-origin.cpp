class Solution {
public:

  vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
  
    priority_queue< pair< int, vector<int> > > pq ;

    for(auto & vec : points){
      int x = vec[0] , y = vec[1] ;
      if(pq.size() < k){
        
        pq.push({ (x)*(x)+(y)*(y) , { x,y } });


      }else if (pq.top().first > (x)*(x)+(y)*(y) ){

        pq.push({ (x)*(x)+(y)*(y) , { x,y } });
        pq.pop();


      }

    }


    vector<vector<int>> res;

    while(!pq.empty()){

      vector<int> v = pq.top().second;
      res.push_back(v);
      pq.pop();

    }
    return res;
  }

};