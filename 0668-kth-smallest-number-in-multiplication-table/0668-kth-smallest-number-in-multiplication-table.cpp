class Solution {
public:
    int countLessOrEqual(int m, int n, int val){
        int cnt = 0, c = n;
        for(int r = 1 ; r <= m ; r++){
            while(c > 0 && r*c > val) c--;
            cnt += c ;
        }
        return cnt;
    }
    int findKthNumber(int m, int n, int k) {
        int l = 1, r = m*n, ans = 0;
        while(l <= r){
            int mid = l + (r-l)/2;
            if(countLessOrEqual(m,n,mid) >= k){
                ans = mid;
                r = mid - 1;
            }else{
                l = mid + 1;
            }
        }
        return ans; 
    }
};