class Solution {
public:
    bool possible(long long row , long long coins){
        long long  sum = (row*(row+1))/2;
        return sum <= coins;
    }
    int arrangeCoins(int n) {
      int left =0 , right = n, ans = 0 ;
      while(right >= left){
          int mid = left +(right - left)/2;
          if(possible(mid,n)){
              left = mid+1; ans = mid;
          }else{
              right = mid -1 ;
          }
      }
      return ans;
    }
};