class Solution {
public:
    int maxArea(vector<int>& arr) {
        int res = 0 ;
        int ptr1 = 0 , ptr2 = arr.size()-1;
        while(ptr1 < ptr2){
            int waterArea = ( min(arr[ptr1] , arr[ptr2]) * (ptr2 - ptr1));
            res = max(res, waterArea);
            if(arr[ptr1] < arr[ptr2]){
                ptr1++;
            }else{
                ptr2--;
            }
        }
        return res;
    }
};
