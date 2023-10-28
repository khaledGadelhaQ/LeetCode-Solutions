class Solution {
public:
    
    bool possible(int s , int h , vector<int> piles){
        long long sum {0};
        for(int i = 0 ; i < piles.size() ; i++){
            sum += ceil(static_cast<double>(piles[i]) / s);
        }
        return sum <= h ;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1, r =*max_element(piles.begin(),piles.end());
        int res;
        while( l <= r){
            int mid = l +(r-l)/2;
            if(possible(mid,h,piles)){
             res = mid;
             r = mid -1;
            }else{
                l = mid +1;
            }
        }
        return res;
    }
};
/*
k is the numbers of bananas koko can eat in an hour
we want to find the smallest number of bananas koko can eat 
before h hours
we can make a function that itreats on all the piles and
count the number of hours koko will take with speed s 
and return the number of hours
3
1 + 2 + 3 + 4
what are the l and r 
l is 1 
r is biggest elemnet in the vector

*/