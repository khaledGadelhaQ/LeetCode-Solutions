class Solution {
public:
    int mySqrt(int x) {
        double MIN = 1e-9;
        double l = 0, r = x;
        while (r - l > MIN) {
            double mid = l + (r - l) / 2;
            if (mid * mid < x) 
                l = mid;
            else 
                r = mid;
            
        }
        return l + MIN;
    }
};
