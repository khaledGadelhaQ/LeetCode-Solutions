class Solution {
public:
    int minimumOperations(vector<int>& nums, int start, int goal) {
        queue<int> q;
        unordered_set<int> visited;
        q.push(start);
        visited.insert(start);
        for(int level = 1 , sz = 1; !q.empty() ; level++, sz = q.size()){
            while(sz--){
                int front = q.front(); 
                q.pop();
                for(int i = 0 ; i < nums.size() ;i++){
                    int opt1 = front + nums[i];
                    int opt2 = front - nums[i];
                    int opt3 = front ^ nums[i];

                    if(opt1 == goal || opt2 == goal || opt3 == goal) 
                      return level;
                     
                    if(opt1 >= 0 && opt1 <= 1000 && visited.find(opt1) == visited.end()){
                        q.push(opt1);
                        visited.insert(opt1);
                    }
                    if(opt2 >= 0 && opt2 <= 1000 && visited.find(opt2) == visited.end()){
                        q.push(opt2);
                        visited.insert(opt2);
                    }
                    if(opt3 >= 0 && opt3 <= 1000 && visited.find(opt3) == visited.end()){
                        q.push(opt3);
                        visited.insert(opt3);
                    }

                }
            }
        }
        return -1;
    }
};
