class Solution {
public:
    int findDuplicate(vector<int>&  v) {
     int slow {0},fast{0};

     while(true){
       slow = v[slow];
       fast = v[v[fast]];
       if(slow == fast)
         break;
     }
     int slow2 {0};

     while(true){
       slow = v[slow];
       slow2 = v[slow2];
       if(slow == slow2)
         break;

     }
     return slow;
    }
};