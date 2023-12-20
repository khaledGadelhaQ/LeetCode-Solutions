class Solution {
public:
    int trap(vector<int>& arr) {
        int ptr1 = 0 , ptr2 = arr.size()-1;
        int res = 0 ;
        int leftHeight = 0 , rightHeight = 0 ;
        while(ptr1 < ptr2){

            if(arr[ptr1] < arr[ptr2]){
                leftHeight = max(leftHeight, arr[ptr1]);
                res += leftHeight - arr[ptr1];
                ptr1++;
            }else{
                rightHeight = max(rightHeight, arr[ptr2]);
                res += rightHeight - arr[ptr2];
                ptr2--;
            }
        }
        return res;

    }
};